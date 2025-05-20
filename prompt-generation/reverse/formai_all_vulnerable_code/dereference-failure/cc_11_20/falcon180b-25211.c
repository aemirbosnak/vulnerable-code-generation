//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(client_addr);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        perror("socket failed");
        exit(errno);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    if (listen(sock, 10) < 0) {
        perror("listen");
        exit(errno);
    }

    while (1) {
        if ((client_sock = accept(sock, (struct sockaddr *)&client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(errno);
        }

        printf("New client connected with IP: %s and port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_sock, buffer, BUFFER_SIZE, 0) <= 0) {
                if (errno!= EAGAIN) {
                    printf("Client disconnected\n");
                    close(client_sock);
                    break;
                }
            }

            printf("Received message: %s\n", buffer);

            if (send(client_sock, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                exit(errno);
            }
        }
    }

    return 0;
}