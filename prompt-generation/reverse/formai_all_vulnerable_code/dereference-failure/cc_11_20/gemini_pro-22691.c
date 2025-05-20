//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

// Struct to hold client information
typedef struct client_info {
    int socket;
    char name[256];
    bool is_authenticated;
} client_info;

// Array to hold client information
client_info clients[MAX_CONNECTIONS];

// Mutex to protect the client array
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    int socket = *(int *)arg;
    free(arg);

    char buffer[256];
    int n;

    // Receive the client's name
    n = recv(socket, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        close(socket);
        return NULL;
    }
    buffer[n] = '\0';

    // Check if the client is already authenticated
    pthread_mutex_lock(&client_mutex);
    bool found = false;
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i].socket == socket) {
            found = true;
            clients[i].is_authenticated = true;
            strcpy(clients[i].name, buffer);
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);

    if (!found) {
        // Send an error message to the client
        n = send(socket, "Error: You are not authenticated.", strlen("Error: You are not authenticated."), 0);
        if (n <= 0) {
            perror("send");
        }
        close(socket);
        return NULL;
    }

    // Send a welcome message to the client
    n = send(socket, "Welcome, ", strlen("Welcome, "), 0);
    if (n <= 0) {
        perror("send");
    }
    n = send(socket, buffer, strlen(buffer), 0);
    if (n <= 0) {
        perror("send");
    }

    // Loop to handle client requests
    while (true) {
        // Receive the client's request
        n = recv(socket, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            perror("recv");
            close(socket);
            return NULL;
        }
        buffer[n] = '\0';

        // Parse the client's request
        char command[256];
        char arg[256];
        sscanf(buffer, "%s %s", command, arg);

        // Handle the client's request
        if (strcmp(command, "turn_on") == 0) {
            // Turn on the light
            printf("Turning on the light.\n");
            n = send(socket, "OK", strlen("OK"), 0);
            if (n <= 0) {
                perror("send");
            }
        } else if (strcmp(command, "turn_off") == 0) {
            // Turn off the light
            printf("Turning off the light.\n");
            n = send(socket, "OK", strlen("OK"), 0);
            if (n <= 0) {
                perror("send");
            }
        } else if (strcmp(command, "exit") == 0) {
            // Exit the program
            printf("Exiting the program.\n");
            n = send(socket, "OK", strlen("OK"), 0);
            if (n <= 0) {
                perror("send");
            }
            close(socket);
            return NULL;
        } else {
            // Send an error message to the client
            n = send(socket, "Error: Invalid command.", strlen("Error: Invalid command."), 0);
            if (n <= 0) {
                perror("send");
            }
        }
    }

    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(struct sockaddr_in);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return -1;
    }

    // Set the server socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the server socket to the address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return -1;
    }

    // Listen for client connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return -1;
    }

    // Loop to handle client connections
    while (true) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client connection
        pthread_t thread;
        int *arg = malloc(sizeof(int));
        *arg = client_socket;
        if (pthread_create(&thread, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }

        // Detach the thread from the main thread
        pthread_detach(thread);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}