//Falcon-180B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int opt = 1;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (master_socket == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(master_socket, MAX_CLIENTS) == -1) {
        perror("listen failed");
        exit(1);
    }

    printf("Server is listening on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(master_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            perror("accept failed");
            continue;
        }

        client_count++;
        printf("Client %d connected\n", client_count);

        if (client_count >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(client_socket);
            continue;
        }

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv failed");
                }
                break;
            }

            printf("Client %d sent: %s\n", client_count, buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("send failed");
                break;
            }
        }

        close(client_socket);
        client_count--;
    }

    close(master_socket);
    return 0;
}