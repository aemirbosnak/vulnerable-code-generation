//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum size of the buffer to receive data from the client
#define MAX_BUFFER_SIZE 1024

// Define the port number to listen on
#define PORT 8080

// Function to handle client connections
void handleClient(int clientSocket) {
    // Buffer to receive data from the client
    char buffer[MAX_BUFFER_SIZE];

    // Receive data from the client
    int numBytesReceived = recv(clientSocket, buffer, MAX_BUFFER_SIZE, 0);

    // Check if there was an error receiving data from the client
    if (numBytesReceived == -1) {
        perror("Error receiving data from client");
        close(clientSocket);
        return;
    }

    // Terminate the string with a null character
    buffer[numBytesReceived] = '\0';

    // Print the data received from the client
    printf("Received data from client: %s\n", buffer);

    // Send data back to the client
    char *message = "Hello from the server!";
    int numBytesSent = send(clientSocket, message, strlen(message) + 1, 0);

    // Check if there was an error sending data to the client
    if (numBytesSent == -1) {
        perror("Error sending data to client");
        close(clientSocket);
        return;
    }

    // Close the client socket
    close(clientSocket);
}

// Main function
int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if there was an error creating the socket
    if (serverSocket == -1) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set the socket options
    int optval = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to the port
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    int bindResult = bind(serverSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

    // Check if there was an error binding the socket to the port
    if (bindResult == -1) {
        perror("Error binding socket to port");
        close(serverSocket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    int listenResult = listen(serverSocket, 5);

    // Check if there was an error listening for incoming connections
    if (listenResult == -1) {
        perror("Error listening for incoming connections");
        close(serverSocket);
        return EXIT_FAILURE;
    }

    // Accept incoming connections
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddr, &clientAddrLen);

        // Check if there was an error accepting the incoming connection
        if (clientSocket == -1) {
            perror("Error accepting incoming connection");
            close(serverSocket);
            return EXIT_FAILURE;
        }

        // Handle the client connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handleClient, (void *) clientSocket);
    }

    // Close the server socket
    close(serverSocket);

    return EXIT_SUCCESS;
}