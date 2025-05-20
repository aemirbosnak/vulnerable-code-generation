//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 8192

// Function prototypes
int create_socket(int port);
void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    int server_socket;
    pthread_t thread_id;

    // Create socket
    server_socket = create_socket(8080);

    // Start listening for connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

        // Start a new thread for each client
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    return 0;
}

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    // Bind server address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    return sockfd;
}

void *handle_client(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[BUFFER_SIZE];

    // Receive data from client
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        // Handle errors
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Client disconnected\n");
            } else {
                printf("Error receiving data\n");
            }
            close(client_socket);
            pthread_exit(0);
        }

        // Forward data to server
        send(client_socket, buffer, bytes_received, 0);
    }
}