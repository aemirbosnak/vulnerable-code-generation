//FormAI DATASET v1.0 Category: Chat server ; Style: all-encompassing
/* C Chat Server Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

/* Function to handle client connections */
void handle_connection(int client_socket, int *client_sockets, int index)
{
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error in receiving data");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client %d disconnected\n", index);
            close(client_socket);
            client_sockets[index] = 0;
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s", index, buffer);
        /* Send the message to all other clients */
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (i == index || client_sockets[i] == 0)
                continue;
            if (send(client_sockets[i], buffer, bytes_received, 0) < 0) {
                perror("Error in sending message");
                exit(EXIT_FAILURE);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int server_socket, client_socket;
    int client_sockets[MAX_CLIENTS] = {0};
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    int opt = 1;

    /* Creating socket file descriptor */
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    /* Set socket options */
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("Error in setting socket options");
        exit(EXIT_FAILURE);
    }

    /* Set server address */
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    /* Bind socket */
    if (bind(server_socket, (struct sockaddr *)&server_address,
             sizeof(server_address)) < 0) {
        perror("Error in binding socket");
        exit(EXIT_FAILURE);
    }

    /* Listen for client connections */
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error in listening for client connections");
        exit(EXIT_FAILURE);
    }
    printf("Server started listening on port %d\n", ntohs(server_address.sin_port));

    while (1) {
        /* Accept client connection */
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address,
                                     &client_address_len)) < 0) {
            perror("Error in accepting client connection");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n",
               inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        /* Find a free slot for the new client */
        int index = -1;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("No free slot for new client\n");
            close(client_socket);
        } else {
            client_sockets[index] = client_socket;
            handle_connection(client_socket, client_sockets, index);
        }
    }

    return 0;
}