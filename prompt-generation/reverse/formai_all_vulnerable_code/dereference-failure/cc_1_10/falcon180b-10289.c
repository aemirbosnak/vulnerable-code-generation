//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CONNECTIONS 10
#define MAX_REQUEST_SIZE 4096
#define PROXY_PORT 8080

int main(int argc, char *argv[]) {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr));
    listen(proxy_socket, MAX_CONNECTIONS);

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        printf("Client connected\n");
        char host[256];
        char request[MAX_REQUEST_SIZE];
        int bytes_received = 0;
        while (1) {
            bytes_received = recv(client_socket, request + bytes_received, MAX_REQUEST_SIZE - bytes_received, 0);
            if (bytes_received == 0) {
                break;
            }
            request[bytes_received] = '\0';
            char *method = strtok(request, " ");
            char *path = strtok(NULL, " ");
            if (strcmp(method, "GET") == 0) {
                char *host_header = strtok(path, " ");
                if (host_header == NULL) {
                    host_header = "/";
                }
                strcpy(host, host_header);
            } else {
                strcpy(host, "/");
            }
            break;
        }
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        inet_pton(AF_INET, host, &server_addr.sin_addr);
        connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
        printf("Connected to %s\n", host);
        while (1) {
            char buffer[MAX_REQUEST_SIZE];
            bytes_received = recv(server_socket, buffer, MAX_REQUEST_SIZE, 0);
            if (bytes_received == 0) {
                break;
            }
            send(client_socket, buffer, bytes_received, 0);
        }
        close(server_socket);
        close(client_socket);
    }
    return 0;
}