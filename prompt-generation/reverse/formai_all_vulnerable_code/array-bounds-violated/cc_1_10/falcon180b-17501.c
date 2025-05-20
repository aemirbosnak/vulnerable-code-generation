//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024
#define PORT 8080
#define SERVER_ADDRESS "127.0.0.1"

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[MAX_MESSAGE_LENGTH];
    int bytes_received;
    while ((bytes_received = recv(client_sockets[(int)socket_desc], buffer, MAX_MESSAGE_LENGTH, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", (int)socket_desc, buffer);
        send(client_sockets[(int)socket_desc], buffer, strlen(buffer), 0);
    }
    close(client_sockets[(int)socket_desc]);
    num_clients--;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        client_sockets[num_clients] = client_socket;
        printf("Client %d connected\n", num_clients);
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    while (num_clients > 0) {
        sleep(1);
    }

    close(server_socket);
    return 0;
}