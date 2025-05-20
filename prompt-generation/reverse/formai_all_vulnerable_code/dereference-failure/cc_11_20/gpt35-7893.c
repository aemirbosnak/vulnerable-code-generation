//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
    int client_sock, proxy_sock, read_size, write_size;
    struct sockaddr_in server_addr, client_addr, proxy_addr;
    char request[MAXSIZE], response[MAXSIZE], buffer[MAXSIZE];

    if (argc != 3) {
        printf("Usage: %s <proxy_port> <server_port>\n", argv[0]);
        exit(1);
    }

    // create a proxy socket
    if ((proxy_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // set proxy socket parameters
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(atoi(argv[1]));

    // bind proxy socket
    if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    // listen on proxy socket
    if (listen(proxy_sock, 5) < 0) {
        perror("Failed to listen on socket");
        exit(1);
    }

    // main loop
    while (1) {
        socklen_t addr_size = sizeof(client_addr);

        // accept incoming connections from client
        if ((client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("Failed to accept connection");
            continue;
        }

        // receive request from client
        memset(request, 0, MAXSIZE);
        if ((read_size = recv(client_sock, request, MAXSIZE, 0)) < 0) {
            perror("Failed to receive from socket");
            close(client_sock);
            continue;
        }

        printf("Received request from client: %s", request);

        // create socket for server
        if ((proxy_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Failed to create socket");
            close(client_sock);
            continue;
        }

        // set server socket parameters
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_addr.sin_port = htons(atoi(argv[2]));

        // connect to server
        if (connect(proxy_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Failed to connect to server");
            close(client_sock);
            continue;
        }

        // send request to server
        if (send(proxy_sock, request, strlen(request), 0) < 0) {
            perror("Failed to send request to server");
            close(client_sock);
            close(proxy_sock);
            continue;
        }

        // receive response from server
        memset(response, 0, MAXSIZE);
        while ((read_size = recv(proxy_sock, buffer, MAXSIZE, 0)) > 0) {
            strcat(response, buffer);
            memset(buffer, 0, MAXSIZE);
        }

        // send response to client
        if (send(client_sock, response, strlen(response), 0) < 0) {
            perror("Failed to send response to client");
            close(client_sock);
            close(proxy_sock);
            continue;
        }

        printf("Sent response to client: %s", response);

        // close sockets
        close(client_sock);
        close(proxy_sock);
    }

    return 0;
}