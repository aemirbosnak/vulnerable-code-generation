//Falcon-180B DATASET v1.0 Category: Chat server ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
int main_socket;

void *handle_client(void *client_socket) {
    int client_socket_copy = *((int *) client_socket);
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket_copy, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_socket_copy);
            clients[num_clients--] = 0;
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket_copy, buffer);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i]!= 0) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
    }

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 10);
    printf("Server started on port 8080\n");

    main_socket = server_socket;

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Maximum number of clients reached\n");
            continue;
        }

        clients[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}