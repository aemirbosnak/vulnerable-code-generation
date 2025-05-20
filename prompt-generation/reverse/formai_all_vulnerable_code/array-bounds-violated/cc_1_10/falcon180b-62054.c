//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080

int clients[MAX_CLIENTS];
int available = 1;
int client_count = 0;

void *handle_client(void *socket_desc) {
    int sock = *(int *) socket_desc;
    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, 1024, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message from client %d: %s", sock, buffer);
    }

    close(sock);
    return NULL;
}

int main() {
    int server_socket, new_socket, addrlen;
    struct sockaddr_in address;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(server_socket, MAX_CLIENTS);

    while (available) {
        addrlen = sizeof(address);
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = new_socket;
                client_count++;
                break;
            }
        }

        if (client_count >= MAX_CLIENTS) {
            send(new_socket, "Server is full. Please try again later.", strlen("Server is full. Please try again later."), 0);
            close(new_socket);
        } else {
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket);
        }
    }

    close(server_socket);
    return 0;
}