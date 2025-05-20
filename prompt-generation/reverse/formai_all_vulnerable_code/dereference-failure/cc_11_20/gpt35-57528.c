//FormAI DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* Our client struct */
typedef struct client {
    struct sockaddr_in address;
    int socket;
    char *name;
} client_t;

/* Define our port number */
#define PORT 8080

int main(int argc, char *argv[]) {
    char buffer[1024];
    int server_socket, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    client_t *clients[100];
    int client_count = 0;

    /* Create the server socket */
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    /* Set socket options */
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    /* Bind the socket to the port */
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    /* Listen for incoming connections */
    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    /* Sherlock Holmes begins his investigation */
    printf("Sherlock: Ah, another day in the life of a private detective. "
           "Let's see who is lurking in the shadows today...\n");

    while (1) {
        /* Accept incoming connections */
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        /* Allocate memory for a client */
        client_t *client = malloc(sizeof(client_t));
        client->socket = new_socket;
        client->address = address;
        client->name = NULL;

        /* Add client to client list */
        clients[client_count++] = client;

        /* Print a message to say we have a new client */
        printf("Sherlock: Aha! We have a new client. Let's see who it is...\n");

        /* Send a welcome message */
        char *welcome_message = "Welcome to Sherlock's chat server. Please enter your name: ";
        send(new_socket, welcome_message, strlen(welcome_message), 0);

        while (1) {
            /* Receive incoming data */
            valread = read(new_socket, buffer, 1024);

            if (valread == 0) {
                /* Client disconnected */
                printf("Sherlock: Oh no, our client has left us. "
                       "Time to solve another mystery...\n");
                break;
            }

            /* Null-terminate the buffer */
            buffer[valread] = '\0';

            /* If the client does not have a name assigned yet, set it */
            if (client->name == NULL) {
                /* Remove newline character from end of name */
                buffer[strcspn(buffer, "\n")] = 0;

                /* Assign client name */
                client->name = strdup(buffer);

                /* Send a welcome message with their name */
                char *welcome_message = malloc(strlen(client->name) + 25);
                sprintf(welcome_message, "Welcome %s, you are now connected.\n", client->name);
                send(new_socket, welcome_message, strlen(welcome_message), 0);
                free(welcome_message);

                /* Print message to let everyone know the new client has joined */
                printf("Sherlock: Ah yes, it's %s. Welcome to the server.\n", client->name);
            } else {
                /* Print message to show the client's message */
                printf("%s: %s", client->name, buffer);

                /* Send message to other clients */
                for (int i = 0; i < client_count; i++) {
                    if (clients[i] != client) {
                        /* Build message */
                        char *message = malloc(strlen(client->name) + strlen(buffer) + 2);
                        sprintf(message, "%s: %s", client->name, buffer);

                        /* Send message */
                        send(clients[i]->socket, message, strlen(message), 0);

                        /* Free memory */
                        free(message);
                    }
                }
            }
        }

        /* Close the socket and remove the client from the list */
        close(new_socket);
        free(client->name);
        free(client);
    }

    return 0;
}