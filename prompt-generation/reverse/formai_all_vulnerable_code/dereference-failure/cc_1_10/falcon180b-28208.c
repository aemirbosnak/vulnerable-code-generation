//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if(argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(proxy_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(atoi(argv[1]));
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if(bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if(listen(proxy_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    while(1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if(client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while(1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if(bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            } else if(bytes_received == -1) {
                printf("Error receiving data: %s\n", strerror(errno));
                break;
            }

            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}