//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *clientHandler(void* clientSocket) {

    int sock = *(int*)clientSocket;
    char buffer[BUFFER_SIZE];
    int messageSize;

    while ((messageSize = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[messageSize] = '\0';
        printf("Received message from client %d: %s\n", sock, buffer);

        // Echo the message back to the client
        send(sock, buffer, strlen(buffer), 0);
    }

    // Remove the client from the connected socket list
    close(sock);
    return NULL;
}

int main() {

    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, clientAddr;
    pthread_t clientThreads[MAX_CLIENTS];
    int clientCount = 0;

    // Create a server socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address struct
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8888);

    // Bind the server address to the socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept a new incoming connection
        int clientSize = sizeof(clientAddr);
        if ((newSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, (socklen_t*)&clientSize)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        // Create a new thread to handle the client
        pthread_create(&clientThreads[clientCount], NULL, clientHandler, &newSocket);
        printf("Connected to client %d\n", newSocket);

        // Increment the client count
        clientCount++;
    }

    return 0;
}