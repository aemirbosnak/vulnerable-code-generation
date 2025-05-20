//FormAI DATASET v1.0 Category: Chat server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE];
    int n, i, j, num_clients = 0;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", atoi(argv[1]));

    while (1) {
        if ((client_socket[num_clients] = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s\n", inet_ntoa(client_address.sin_addr));
        num_clients++;

        while (1) {
            memset(buffer, 0, MAX_BUFFER_SIZE);

            if ((n = recv(client_socket[i], buffer, MAX_BUFFER_SIZE, 0)) < 0) {
                perror("recv failed");
                exit(EXIT_FAILURE);
            }

            if (n == 0) {
                printf("Client %s disconnected\n", inet_ntoa(client_address.sin_addr));
                close(client_socket[i]);
                num_clients--;
                break;
            }

            printf("Received message from client %s: %s", inet_ntoa(client_address.sin_addr), buffer);

            for (j = 0; j < num_clients; j++) {
                if (client_socket[j] != client_socket[i]) {
                    send(client_socket[j], buffer, n, 0);
                }
            }
        }
    }

    return 0;
}