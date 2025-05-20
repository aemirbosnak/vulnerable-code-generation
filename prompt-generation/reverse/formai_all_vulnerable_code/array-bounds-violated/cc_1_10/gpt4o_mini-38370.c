//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void* handle_client(void* socket_desc);
void error_exit(const char* msg);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_exit("Socket failed");
    }
    printf("Grateful for the opportunity! Socket created.\n");

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_exit("Set socket options failed");
    }
    printf("The socket options are set cheerfully!\n");

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        error_exit("Bind failed");
    }
    printf("Socket bound to port %d with gratitude!\n", PORT);

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        error_exit("Listen failed");
    }
    printf("Listening for connections... The spirit of communication is alive!\n");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            error_exit("Accept failed");
        }
        printf("A new client has connected! Let's engage in joyful conversation.\n");

        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void*)&new_socket) != 0) {
            error_exit("Failed to create thread for client");
        }
        printf("Thread for client created successfully. Cheers to collaboration!\n");
    }

    close(server_fd);
    return 0;
}

void* handle_client(void* socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communicate with the client
    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Client says: %s", buffer);

        // Echoing back to the client
        send(sock, buffer, read_size, 0);
        printf("Echoed back to client: %s", buffer);
    }

    if (read_size == 0) {
        printf("Client disconnected with grace. Happily moving on!\n");
    } else if (read_size == -1) {
        perror("Recv failed");
    }

    free(socket_desc);
    close(sock);
    return NULL;
}

void error_exit(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}