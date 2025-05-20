//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if(argc < 4) {
        printf("Usage: %s <proxy_port> <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char* server_ip = argv[2];
    int server_port = atoi(argv[3]);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    if(connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(proxy_socket == -1) {
        printf("Error: %s\n", strerror(errno));
        close(server_socket);
        return 1;
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    if(bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        close(server_socket);
        close(proxy_socket);
        return 1;
    }

    if(listen(proxy_socket, 10) == -1) { // Allow 10 pending connections
        printf("Error: %s\n", strerror(errno));
        close(server_socket);
        close(proxy_socket);
        return 1;
    }

    printf("Proxy server is running on port %d\n", proxy_port);

    while(1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if(client_socket == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        printf("New client connected\n");

        char buffer[BUFFER_SIZE];
        ssize_t recv_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if(recv_count == -1) {
            printf("Error: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        printf("Received request\n");

        if(send(server_socket, buffer, recv_count, 0) == -1) {
            printf("Error: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        printf("Sent request to server\n");

        while(1) {
            ssize_t recv_count = recv(server_socket, buffer, BUFFER_SIZE, 0);
            if(recv_count == -1) {
                printf("Error: %s\n", strerror(errno));
                close(client_socket);
                break;
            }

            if(send(client_socket, buffer, recv_count, 0) == -1) {
                printf("Error: %s\n", strerror(errno));
                close(client_socket);
                break;
            }

            if(recv_count == 0) { // End of file
                printf("Connection closed by server\n");
                break;
            }
        }

        close(client_socket);
        printf("Client disconnected\n");
    }

    close(server_socket);
    close(proxy_socket);
    return 0;
}