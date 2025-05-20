//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d: %s\n", client_socket, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i]!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
    close(client_socket);
    printf("Client %d disconnected\n", client_socket);
}

void *accept_connections(void *arg) {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }
        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }
        client_sockets[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port 8080\n");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, accept_connections, NULL);

    while (1) {
        sleep(1000);
    }

    return 0;
}