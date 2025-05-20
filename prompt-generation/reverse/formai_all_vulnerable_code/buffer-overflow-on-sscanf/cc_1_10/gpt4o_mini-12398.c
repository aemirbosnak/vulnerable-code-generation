//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192
#define PORT 8080

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }

    buffer[bytes_received] = '\0';
    printf("Request:\n%s\n", buffer);

    char method[10], url[256], protocol[10];
    sscanf(buffer, "%s %s %s", method, url, protocol);
    
    if (strcasecmp(method, "GET") != 0) {
        printf("Only GET method is supported\n");
        close(client_socket);
        return;
    }

    char *host_start = strstr(url, "//");
    if (host_start == NULL) {
        close(client_socket);
        return;
    }

    host_start += 2;
    char *host_end = strstr(host_start, "/");
    if (host_end == NULL) {
        host_end = host_start + strlen(host_start);
    }

    char host[256];
    strncpy(host, host_start, host_end - host_start);
    host[host_end - host_start] = '\0';

    int target_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (target_socket < 0) {
        perror("Unable to create socket to target");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(inet_ntoa((struct in_addr) { .s_addr = inet_addr(host) }));

    if (connect(target_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to target server failed");
        close(client_socket);
        close(target_socket);
        return;
    }

    send(target_socket, buffer, bytes_received, 0);

    while ((bytes_received = recv(target_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    close(target_socket);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Unable to create server socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Accepted a connection\n");
        
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}