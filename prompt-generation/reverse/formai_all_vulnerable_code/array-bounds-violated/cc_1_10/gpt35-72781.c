//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void *connection_handler(void *);

int main(int argc, char const *argv[]) {

    int socket_desc, client_sock, c;
    struct sockaddr_in server, client;

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }

    // Set socket options
    int optval = 1;
    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        printf("Could not set socket options");
        return 1;
    }

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Bind failed");
        return 1;
    }

    // Listen for incoming connections
    listen(socket_desc, 3);

    printf("Listening on port %d...\n", PORT);

    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&c))) {
        printf("Connection accepted\n");

        // Create a thread to handle the connection
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, connection_handler, (void *)&client_sock) < 0) {
            printf("Could not create thread\n");
            return 1;
        }

        // Detach the thread to allow it to run independently
        pthread_detach(thread_id);
    }

    if (client_sock < 0) {
        printf("Accept failed\n");
        return 1;
    }

    return 0;
}

/*
 * This function handles the communication between the client and the server.
 * Each thread created by the main function will execute this function.
 */
void *connection_handler(void *client_sock_ptr) {

    int client_sock = *(int *)client_sock_ptr;
    int read_size;
    char client_message[2000], *message;

    // Receive a message from the client
    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
        // Set the string terminating NULL byte on the end of the data read
        client_message[read_size] = '\0';

        // Prepare the message to send it back to the client
        message = malloc(strlen(client_message) + 1);
        strcpy(message, client_message);

        // Send the message back to the client
        write(client_sock, message, strlen(message));
        free(message);

        // Clear the buffer
        memset(client_message, 0, 2000);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        printf("Receive failed\n");
    }

    // Free the pointer allocated for the client socket descriptor
    free(client_sock_ptr);

    return NULL;
}