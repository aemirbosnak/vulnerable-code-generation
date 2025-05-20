//FormAI DATASET v1.0 Category: Client Server Application ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5     // maximum number of clients that can be connected
#define BUFFER_SIZE 1024  // buffer size for sending/receiving messages

void *client_thread(void *arg);  // function that will run for each client in a new thread

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, addr_len, client_index = 0;
    struct sockaddr_in server_addr, client_addr;
    pthread_t client_threads[MAX_CLIENTS];

    // create a socket for the server
    if ((server_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // initialize the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    // bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming client connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port 8000...\n");

    // loop to accept client connections
    while (1) {
        addr_len = sizeof(client_addr);

        // accept a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) == -1) {
            perror("accept() failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d (socket = %d)\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), client_socket);

        // spawn a new thread to handle the client
        pthread_create(&client_threads[client_index], NULL, client_thread, (void *)&client_socket);

        client_index++;

        // if the maximum number of clients have been connected, stop accepting new connections
        if (client_index >= MAX_CLIENTS) {
            printf("Maximum number of clients connected.\n");
            break;
        }
    }

    // join all client threads before exiting the program
    for (int i = 0; i < client_index; i++) {
        pthread_join(client_threads[i], NULL);
    }

    return 0;
}

void *client_thread(void *arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // loop to receive and send messages to/from the client
    while (1) {
        // receive a message from the client
        if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) == -1) {
            perror("recv() failed");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received message (%d bytes): %s\n", bytes_received, buffer);

        // send a response to the client
        if (send(client_socket, "Message received by the server.", 31, 0) == -1) {
            perror("send() failed");
            break;
        }
    }

    // close the client socket and exit the thread
    close(client_socket);
    pthread_exit(NULL);
}