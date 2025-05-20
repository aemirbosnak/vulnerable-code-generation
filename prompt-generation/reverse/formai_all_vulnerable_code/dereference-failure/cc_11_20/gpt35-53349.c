//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER_PORT 80
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char *server_name = argv[1];
    char *server_ip;
    char request[MAX_SIZE], response[MAX_SIZE];

    // Get server IP from hostname
    struct hostent *he;
    if ((he = gethostbyname(server_name)) == NULL) {
        printf("Get server IP error\n");
        exit(1);
    }
    server_ip = inet_ntoa(*((struct in_addr*)he->h_addr_list[0]));

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Create server socket error\n");
        exit(1);
    }

    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Set server socket options error\n");
        exit(1);
    }

    // Bind server socket to local address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Bind server socket to local address error\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        printf("Listen for incoming connections error\n");
        exit(1);
    }
    printf("Proxy server is listening on port %d\n", SERVER_PORT);

    while (1) {
        // Accept client connection
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_len)) < 0) {
            printf("Accept client connection error\n");
            continue;
        }
        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive client request
        memset(request, 0, MAX_SIZE);
        if (recv(client_fd, request, MAX_SIZE, 0) < 0) {
            printf("Receive client request error\n");
            close(client_fd);
            continue;
        }
        printf("Received client request:\n%s\n", request);

        // Create new socket to connect to server
        int server_sock_fd;
        if ((server_sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            printf("Create server socket error\n");
            close(client_fd);
            continue;
        }

        // Connect to server with new socket
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
            printf("Invalid server IP address\n");
            close(client_fd);
            close(server_sock_fd);
            continue;
        }
        if (connect(server_sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            printf("Connect to server error\n");
            close(client_fd);
            close(server_sock_fd);
            continue;
        }

        // Send client request to server
        if (send(server_sock_fd, request, strlen(request), 0) < 0) {
            printf("Send client request to server error\n");
            close(client_fd);
            close(server_sock_fd);
            continue;
        }

        // Receive server response
        memset(response, 0, MAX_SIZE);
        if (recv(server_sock_fd, response, MAX_SIZE, 0) < 0) {
            printf("Receive server response error\n");
            close(client_fd);
            close(server_sock_fd);
            continue;
        }
        printf("Received server response:\n%s\n", response);

        // Send server response to client
        if (send(client_fd, response, strlen(response), 0) < 0) {
            printf("Send server response to client error\n");
            close(client_fd);
            close(server_sock_fd);
            continue;
        }

        close(client_fd);
        close(server_sock_fd);
    }

    return 0;
}