//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

#define PROXY_PORT 8888
#define MAX_BUF_LEN 1024

void handle_request(int client_socket);

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    // Create proxy server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PROXY_PORT);

    // Bind server address to socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening at port %d\n", PROXY_PORT);

    while (1)
    {
        // Accept incoming client connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen))<0)
        {
            perror("Accept error");
            continue;
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client request
        handle_request(client_socket);
    }

    return 0;
}

void handle_request(int client_socket)
{
    char buffer[MAX_BUF_LEN] = {0};
    char url[MAX_BUF_LEN] = {0};
    char *host = NULL;
    int bytes_recv, total_bytes_recv = 0;
    int server_socket;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);

    // Receive client request
    bytes_recv = recv(client_socket, buffer, MAX_BUF_LEN, 0);
    if (bytes_recv < 0)
    {
        perror("Recv error");
        close(client_socket);
        return;
    }

    // Extract requested URL
    if (sscanf(buffer, "GET http://%s", url) != 1)
    {
        fprintf(stderr, "Invalid request format\n");
        close(client_socket);
        return;
    }

    printf("Requested URL: %s\n", url);

    // Extract host information from URL
    host = strtok(url, "/");
    strcat(url, strstr(buffer, "\n"));

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket creation error");
        close(client_socket);
        return;
    }

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(80);

    // Connect to server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection error");
        close(client_socket);
        return;
    }

    // Send request to server
    if (send(server_socket, buffer, strlen(buffer), 0) < 0)
    {
        perror("Send error");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Receive response from server
    while ((bytes_recv = recv(server_socket, buffer, MAX_BUF_LEN, 0)) > 0)
    {
        if (send(client_socket, buffer, bytes_recv, 0) < 0)
        {
            perror("Send error");
            close(server_socket);
            close(client_socket);
            return;
        }
        total_bytes_recv += bytes_recv;
    }

    printf("Total bytes received: %d\n", total_bytes_recv);

    // Close sockets
    close(server_socket);
    close(client_socket);
}