//FormAI DATASET v1.0 Category: Client Server Application ; Style: portable
// This is a simple Client Server Application example in C
// The Server will listen to incoming connections from multiple Clients
// The Clients will send a string to the Server, which the Server will capitalize and send back to the Clients

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5

int server_fd, new_socket, client_sockets[MAX_CLIENTS];
struct sockaddr_in address;
int addrlen = sizeof(address);

// Function to capitalize the string
char* capitalize(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

// Function to handle the incoming connections from the Clients
void* handle_connection(void* arg) {
    int socket_id = *(int*)arg;
    char buffer[1024];
    char* capitalized;

    while (1) {
        int valread = read(socket_id, buffer, 1024);
        if (valread == 0) {
            // Client closed the connection
            printf("Connection terminated with Client %d\n", socket_id);
            client_sockets[socket_id] = 0;
            return NULL;
        } else {
            buffer[valread] = '\0';
            capitalized = capitalize(buffer);
            write(socket_id, capitalized, strlen(capitalized));
        }
    }
}

int main(int argc, char const *argv[]) {
    // Creating the Server Socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Setting the Server Address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the Server to the specified Address and PORT
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on PORT %d\n", PORT);

    // Handling the incoming connections from Clients
    pthread_t thread_id;
    int socket_id;
    while (1) {
        // Accepting the incoming connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting connection failed");
            exit(EXIT_FAILURE);
        }

        // Adding the new Client socket to the client_sockets array
        for (int i = 1; i <= MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                socket_id = i;
                break;
            }
        }

        printf("Connection established with Client %d\n", socket_id);

        // Creating a new thread for handling the Client connection
        if (pthread_create(&thread_id, NULL, handle_connection, (void*)&client_sockets[socket_id]) < 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}