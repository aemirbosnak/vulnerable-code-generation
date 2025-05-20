//FormAI DATASET v1.0 Category: Networking ; Style: relaxed
// Hey there, let's create a simple networking program in C!
// In this program, we'll create a client-server model where the client will send a message to the server
// And the server will read and display the message.

// First, let's include the necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// Let's define the buffer size for our message exchange.
#define BUFFER_SIZE 1024

// Function to handle any errors during socket creation.
void error(char* message) {
    perror(message);
    exit(1);
}

int main() {
    // Let's declare our variables.
    int clientSocket, portNumber;
    char serverIp[20], message[BUFFER_SIZE];

    // Get the IP address and port number from the user.
    printf("Enter the server IP address: ");
    scanf("%s", serverIp);
    printf("Enter the server port number: ");
    scanf("%d", &portNumber);

    // Create a socket.
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        error("Error in creating socket.");
    }

    // Define the server address.
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNumber);
    serverAddress.sin_addr.s_addr = inet_addr(serverIp);

    // Create a connection with the server.
    int connectionStatus = connect(clientSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));
    if (connectionStatus == -1) {
        error("Error in connecting to server.");
    }

    // Send the message to the server.
    printf("Enter the message to send: ");
    getchar();  // To clear the input buffer.
    fgets(message, BUFFER_SIZE, stdin);
    send(clientSocket, message, strlen(message), 0);

    // Receive the message from the server.
    char receivedMessage[BUFFER_SIZE];
    int bytesRead = recv(clientSocket, receivedMessage, BUFFER_SIZE, 0);
    if (bytesRead == -1) {
        error("Error in receiving message from server.");
    }
    receivedMessage[bytesRead] = '\0';

    // Display the received message.
    printf("Message received from server: %s\n", receivedMessage);

    // Close the socket.
    close(clientSocket);

    return 0;
}