//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PROXY_PORT 8080
#define MAX_BUF_SIZE 2048

int main(int argc, char *argv[]) {
    int proxy_fd, client_fd, server_fd, len, n;
    char buffer[MAX_BUF_SIZE];
    struct sockaddr_in proxy_addr, client_addr, server_addr;
   
    // Create socket for proxy server
    if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Proxy socket creation failed");
        exit(1);
    }
   
    // Bind the proxy socket
    memset((char *)&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(PROXY_PORT);
    if (bind(proxy_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Proxy socket bind failed");
        exit(1);
    }
   
    // Listen for incoming connections
    if (listen(proxy_fd, 5) < 0) {
        perror("Proxy socket listen failed");
        exit(1);
    }
   
    printf("Surrealist Simple HTTP Proxy Server running on port %d...\n", PROXY_PORT);
   
    while (1) {
        len = sizeof(client_addr);
        if ((client_fd = accept(proxy_fd,
                                (struct sockaddr *)&client_addr,
                                &len)) < 0) {
            perror("Proxy socket accept failed");
            exit(1);
        }
       
        if (!fork()) {
            // Child process
            close(proxy_fd);
           
            // Create socket for server
            if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("Server socket creation failed");
                exit(1);
            }
           
            memset((char *)&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(80);
           
            // Get server IP from client HTTP request
            char request_buffer[MAX_BUF_SIZE];
            memset(request_buffer, 0, MAX_BUF_SIZE);
            recv(client_fd, request_buffer, MAX_BUF_SIZE, 0);
            char *host_position = strstr(request_buffer, "Host: ");
            char *hostname = strtok(host_position, " \r\n");
            char *ip_addr = NULL;
            struct hostent *host_entry;
            host_entry = gethostbyname(hostname);
            if (host_entry == NULL) {
                printf("Failed to resolve server IP address\n");
                continue;
            }
            ip_addr = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));
            server_addr.sin_addr.s_addr = inet_addr(ip_addr);
           
            // Connect to server
            if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("Server socket connection failed");
                exit(1);
            }
           
            // Send client's HTTP request to server
            send(server_fd, request_buffer, strlen(request_buffer), 0);
           
            // Forward server's HTTP response to client
            int response_len = 0;
            while ((response_len = recv(server_fd, buffer, MAX_BUF_SIZE, 0)) > 0) {
                send(client_fd, buffer, response_len, 0);
                memset(buffer, 0, MAX_BUF_SIZE);
            }
           
            close(server_fd);
            close(client_fd);
            exit(0);
        }
        // Parent process
        close(client_fd);
    }
   
    return 0;
}