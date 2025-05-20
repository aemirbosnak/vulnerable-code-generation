//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void *client_handler(void *arg){
    int client_socket = *(int*) arg;
    char buffer[BUFFER_SIZE];
    int recv_size;

    while((recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0){
        buffer[recv_size] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    printf("Client %d disconnected\n", client_socket);
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]){
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1){
        printf("Error creating server socket\n");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    // Bind the socket to the server address
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1){
        printf("Error binding server socket\n");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if(listen(server_socket, 3) == -1){
        printf("Error listening for connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port 8888\n");

    while(1){
        // Accept a connection from the client
        struct sockaddr_in client_address;
        int client_size = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, (socklen_t*) &client_size);

        if(client_socket == -1){
            printf("Error accepting client connection\n");
            continue;
        }

        printf("Client %d connected\n", client_socket);

        // Create a new thread to handle the client
        pthread_t new_thread;
        if(pthread_create(&new_thread, NULL, client_handler, (void *)&client_socket) != 0){
            printf("Error creating new thread\n");
            continue;
        }

        // Detach the new thread so it can run independently
        pthread_detach(new_thread);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}