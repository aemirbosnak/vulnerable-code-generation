//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket;
    struct sockaddr_in proxy_addr, client_addr;
    char buffer[BUFFER_SIZE];

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(8080);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(proxy_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int client_len = sizeof(client_addr);
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, &client_len);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(proxy_socket);
    return 0;
}