//Falcon-180B DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int*)client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", *((int*)client_socket), buffer);

        // Send message to all clients except the sender
        for (int i = 0; i < num_clients; i++) {
            if (i!= *((int*)client_socket)) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(*((int*)client_socket));
    num_clients--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server started on port 12345\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            send(new_socket, "Server full\n", 11, 0);
            close(new_socket);
        } else {
            client_sockets[num_clients] = new_socket;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket);
        }
    }

    return 0;
}