//FormAI DATASET v1.0 Category: Client Server Application ; Style: relaxed
// This program demonstrates a simple client-server communication model
// The server listens for an incoming connection from the client and responds with a welcome message
// The client sends a message to the server and displays the response on the terminal

// Import the necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

// Define a constant for the buffer size
#define BUFFER_SIZE 256

int main() {
    // Instantiate the necessary variables
    int serverSocket, clientSocket, portNumber, connectionStatus;
    socklen_t clientLength;
  
    // Create a buffer to store the incoming message from the client
    char buffer[BUFFER_SIZE];

    // Define the server and client address structures
    struct sockaddr_in serverAddress, clientAddress;

    // Prompt the user to enter a port number
    printf("Enter the port number that you want to use: ");
    scanf("%d", &portNumber);

    // Create a socket for the server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if there was an error creating the socket
    if (serverSocket < 0) {
        printf("Error: Unable to open socket.\n");
        return 1;
    }

    // Clear the server address structure
    memset(&serverAddress, 0, sizeof(serverAddress));

    // Set the server address parameters
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    // Bind the socket to the server address
    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        printf("Error: Unable to bind socket.\n");
        return 1;
    }

    // Wait for incoming connections
    listen(serverSocket, 1);
    printf("Server listening on port %d.\n", portNumber);

    // Accept incoming connections
    clientLength = sizeof(clientAddress);
    clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientLength);

    // Check if there was an error accepting the connection
    if (clientSocket < 0) {
        printf("Error: Unable to accept connection.\n");
        return 1;
    }

    // Send a welcome message to the client
    connectionStatus = write(clientSocket, "Welcome to the server.\n", strlen("Welcome to the server.\n") + 1);

    // Check if there was an error sending the message
    if (connectionStatus < 0) {
        printf("Error: Unable to send message.\n");
        return 1;
    }

    // Receive a message from the client
    connectionStatus = read(clientSocket, buffer, BUFFER_SIZE);

    // Check if there was an error receiving the message
    if (connectionStatus < 0) {
        printf("Error: Unable to receive message.\n");
        return 1;
    }

    // Display the message received from the client
    printf("Client message: %s\n", buffer);

    // Close the client and server sockets
    close(clientSocket);
    close(serverSocket);

    // Return 0 if the program completes successfully
    return 0;
}