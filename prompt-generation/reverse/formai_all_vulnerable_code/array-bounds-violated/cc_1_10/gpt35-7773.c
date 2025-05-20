//FormAI DATASET v1.0 Category: Networking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PENDING 5 /* maximum number of pending connections to the server */
#define BUFFER_SIZE 256 /* maximum size of buffer */

void handle_client(int client_socket);

int main(int argc, char *argv[]) {
    int server_socket, client_socket, addr_len, port;
    struct sockaddr_in server_addr, client_addr;

    /* check for command line arguments */
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* convert port number from string to integer */
    port = atoi(argv[1]);

    /* create socket */
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    /* configure server address */
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    /* bind socket to server address */
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    /* listen for incoming connections */
    if (listen(server_socket, MAX_PENDING) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", port);

    /* accept incoming connections and handle them */
    while (1) {
        addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len)) < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }
        printf("Client connected (IP: %s, Port: %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        handle_client(client_socket);
        close(client_socket);
        printf("Client disconnected (IP: %s, Port: %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    /* receive data from client */
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received from client: %s", buffer);
        /* send data back to client */
        if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else {
        perror("Failed to receive data from client");
        exit(EXIT_FAILURE);
    }
}