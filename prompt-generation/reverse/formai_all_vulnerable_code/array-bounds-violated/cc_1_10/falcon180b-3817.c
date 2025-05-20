//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define PORT 8080
#define SERVER_IP "127.0.0.1"

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void* handle_client(void* client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);

        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i]!= client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client_socket);
    num_clients--;
}

int main() {
    pthread_t threads[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full\n", 16, 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;

            pthread_create(&threads[num_clients - 1], NULL, handle_client, (void*)client_socket);
        }
    }

    return 0;
}