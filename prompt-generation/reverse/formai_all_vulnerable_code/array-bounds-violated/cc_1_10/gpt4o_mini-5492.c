//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void sendCommand(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) < 0) {
        handleError("Failed to send command");
    }
}

void receiveResponse(int socket) {
    char buffer[BUFFER_SIZE];
    int bytesReceived = recv(socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytesReceived < 0) {
        handleError("Failed to receive response");
    }
    
    buffer[bytesReceived] = '\0'; // Null-terminate the string
    printf("Server Response: %s", buffer);
}

void pop3Login(int socket, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    sendCommand(socket, command);
    receiveResponse(socket);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    sendCommand(socket, command);
    receiveResponse(socket);
}

void listEmails(int socket) {
    sendCommand(socket, "LIST\r\n");
    receiveResponse(socket);
}

void retrieveEmail(int socket, const char *emailNumber) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", emailNumber);
    sendCommand(socket, command);
    receiveResponse(socket);
}

void quitPOP3(int socket) {
    sendCommand(socket, "QUIT\r\n");
    receiveResponse(socket);
    close(socket);
}

int main() {
    int socketDescriptor;
    struct sockaddr_in serverAddress;

    const char *serverIP = "127.0.0.1"; // Change to your POP3 server IP
    const char *username = "your_username"; // Set your username
    const char *password = "your_password"; // Set your password

    // Create socket
    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Socket creation failed");
    }

    // Configure server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, serverIP, &serverAddress.sin_addr) <= 0) {
        handleError("Invalid address");
    }

    // Connect to the POP3 server
    if (connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        handleError("Connection to server failed");
    }

    // Receive initial server response
    receiveResponse(socketDescriptor);
    
    // Log in to the POP3 server
    pop3Login(socketDescriptor, username, password);

    // List emails
    listEmails(socketDescriptor);

    // Retrieve the first email (for example)
    retrieveEmail(socketDescriptor, "1");

    // Quit the POP3 session
    quitPOP3(socketDescriptor);

    return 0;
}