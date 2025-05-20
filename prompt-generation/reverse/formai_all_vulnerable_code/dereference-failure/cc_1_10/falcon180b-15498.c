//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define PORT 8080

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg);

int main() {
    int server_socket, new_socket, addrlen, client_socket;
    struct sockaddr_in server_addr, client_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        for (int i = 0; i < num_clients; i++) {
            if (clients[i] == 0) {
                clients[i] = new_socket;
                num_clients++;
                break;
            }
        }

        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(new_socket);
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)new_socket);
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;

    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        printf("Received data from client: %s\n", buffer);
    }

    close(client_socket);
    return NULL;
}