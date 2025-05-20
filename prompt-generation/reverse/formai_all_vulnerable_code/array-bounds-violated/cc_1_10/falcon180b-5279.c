//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket_desc, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", *(int*)socket_desc, buffer);
        send(socket_desc, buffer, bytes_received, 0);
    }

    close(*(int*)socket_desc);
    pthread_exit(NULL);
}

void accept_connections() {
    int addrlen;
    struct sockaddr_in client_addr;

    while (num_clients < MAX_CLIENTS) {
        addrlen = sizeof(client_addr);
        client_sockets[num_clients] = accept(server_socket, (struct sockaddr*)&client_addr, &addrlen);

        if (client_sockets[num_clients] < 0) {
            printf("Error accepting connection\n");
        } else {
            printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void*)&client_sockets[num_clients]);
            num_clients++;
        }
    }
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 3) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    accept_connections();

    return 0;
}