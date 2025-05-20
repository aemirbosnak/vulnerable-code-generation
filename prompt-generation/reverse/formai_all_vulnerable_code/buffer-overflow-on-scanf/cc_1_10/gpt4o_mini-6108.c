//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110 // Default POP3 port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void sendCommand(int sock, const char *cmd) {
    // Send command to the POP3 server
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
}

void readResponse(int sock) {
    // Read response from the POP3 server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer)); // Clear buffer
    int bytesReceived = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytesReceived < 0) {
        error("Error receiving response");
    }
    printf("%s", buffer); // Print server response
}

void pop3Login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];
    
    // Send USER command
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    sendCommand(sock, command);
    readResponse(sock);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    sendCommand(sock, command);
    readResponse(sock);
}

void listEmails(int sock) {
    char command[] = "LIST\r\n";
    sendCommand(sock, command);
    readResponse(sock);
}

void retrieveEmail(int sock, int messageNumber) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %d\r\n", messageNumber);
    sendCommand(sock, command);
    readResponse(sock);
}

void quitPop3(int sock) {
    char command[] = "QUIT\r\n";
    sendCommand(sock, command);
    readResponse(sock);
}

int main() {
    char *serverAddress = "YOUR_POP3_SERVER"; // Replace with your POP3 server
    char username[100];
    char password[100];
    
    printf("Welcome to the POP3 Client!\n");

    // Get user credentials
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error opening socket");
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(serverAddress);

    // Connect to the POP3 server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }

    // Read server greeting
    readResponse(sock);
    
    // Login to POP3 server
    pop3Login(sock, username, password);
    
    // List emails
    printf("Listing emails...\n");
    listEmails(sock);
    
    // Retrieve emails based on user input
    int messageNumber;
    printf("Enter the message number to retrieve (or 0 to skip): ");
    scanf("%d", &messageNumber);
    if (messageNumber > 0) {
        printf("Retrieving email #%d...\n", messageNumber);
        retrieveEmail(sock, messageNumber);
    }
    
    // Quit from the POP3 server gracefully
    quitPop3(sock);
    
    // Close the socket
    close(sock);
    printf("Disconnected from POP3 server. Goodbye!\n");
    return 0;
}