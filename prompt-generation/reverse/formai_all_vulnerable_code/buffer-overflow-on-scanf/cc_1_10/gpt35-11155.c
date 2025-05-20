//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

// function to create a socket connection
int createSocket(char* serverAddress, int port) {

    // Create a socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation was successful
    if (clientSocket == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    // Set up the server address structure
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);

    // Convert server address string to binary
    if (inet_pton(AF_INET, serverAddress, &serverAddr.sin_addr) == -1) {
        printf("Invalid server address\n");
        exit(1);
    }

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    return clientSocket;
}

int main() {

    // Welcome message
    printf("Welcome to the SMTP client program!\n");

    // Prompt user for server address and port number
    char serverAddress[30];
    int port;
    printf("Enter server address: ");
    scanf("%s", serverAddress);
    printf("Enter server port: ");
    scanf("%d", &port);

    // Create a socket connection with the server
    int clientSocket = createSocket(serverAddress, port);
    printf("Connected to server at %s:%d\n", serverAddress, port);

    // Get the initial server response
    char serverResponse[1024];
    recv(clientSocket, serverResponse, sizeof(serverResponse)-1, 0);
    printf("Server response: %s\n", serverResponse);

    // Send HELO command to server
    char heloCommand[100] = "HELO mydomain.com\r\n";
    send(clientSocket, heloCommand, strlen(heloCommand), 0);
    printf("Sent HELO command to server\n");

    // Get server response after sending HELO command
    recv(clientSocket, serverResponse, sizeof(serverResponse)-1, 0);
    printf("Server response: %s\n", serverResponse);

    // Prompt user for sender and recipient email addresses
    char fromAddress[100];
    char toAddress[100];
    printf("Enter sender email address: ");
    scanf("%s", fromAddress);
    printf("Enter recipient email address: ");
    scanf("%s", toAddress);

    // Construct the email message
    char message[1000];
    sprintf(message, "From: <%s>\r\nTo: <%s>\r\nSubject: Test email\r\n\r\nThis is a test email from the SMTP client program.\r\n.\r\n", fromAddress, toAddress);

    // Send email message to server
    send(clientSocket, message, strlen(message), 0);
    printf("Sent email message to server\n");

    // Get server response after sending email message
    recv(clientSocket, serverResponse, sizeof(serverResponse)-1, 0);
    printf("Server response: %s\n", serverResponse);

    // Close the socket connection with the server
    close(clientSocket);
    printf("Disconnected from server\n");

    return 0;
}