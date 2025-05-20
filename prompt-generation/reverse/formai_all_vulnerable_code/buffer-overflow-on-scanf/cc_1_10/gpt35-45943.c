//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_ADDR "smtp.gmail.com"
#define SERVER_PORT 465

int main() {

    printf("%s\n", "Welcome to SMTP Client Program!");
    printf("%s\n", "Surprised? Yeah! You are building your own SMTP client program!");

    // Create socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        printf("%s\n", "Failed to create socket!");
        exit(1);
    }
    printf("%s\n", "Socket created successfully!");

    // Set server address
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    serverAddr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        printf("%s\n", "Failed to connect to server!");
        exit(1);
    }
    printf("%s\n", "Connected to server successfully!");

    // Receive welcome message
    char welcomeMsg[1024];
    recv(clientSocket, welcomeMsg, 1024, 0);
    printf("%s\n", welcomeMsg);

    // Send sender's email address
    char senderAddr[100];
    printf("%s\n", "Enter your email address:");
    scanf("%s", senderAddr);
    char cmd[1024];
    sprintf(cmd, "EHLO %s\r\n", senderAddr);
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);

    // Send authentication information
    char username[100], password[100];
    printf("%s\n", "Enter your Gmail username:");
    scanf("%s", username);
    printf("%s\n", "Enter your Gmail password:");
    scanf("%s", password);
    sprintf(cmd, "AUTH LOGIN\r\n");
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);
    sprintf(cmd, "%s\r\n", username);
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);
    sprintf(cmd, "%s\r\n", password);
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);

    // Send recipient's email address
    char recipientAddr[100];
    printf("%s\n", "Enter recipient's email address:");
    scanf("%s", recipientAddr);
    sprintf(cmd, "MAIL FROM: <%s>\r\n", senderAddr);
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);
    sprintf(cmd, "RCPT TO: <%s>\r\n", recipientAddr);
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);

    // Send email content
    char subject[100], content[1024];
    printf("%s\n", "Enter email subject:");
    scanf("%s", subject);
    printf("%s\n", "Enter email content:");
    scanf("%s", content);
    sprintf(cmd, "DATA\r\n");
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);
    sprintf(cmd, "From: <%s>\r\n", senderAddr);
    send(clientSocket, cmd, strlen(cmd), 0);
    memset(cmd, 0, 1024);
    sprintf(cmd, "To: <%s>\r\n", recipientAddr);
    send(clientSocket, cmd, strlen(cmd), 0);
    memset(cmd, 0, 1024);
    sprintf(cmd, "Subject: %s\r\n\r\n", subject);
    send(clientSocket, cmd, strlen(cmd), 0);
    memset(cmd, 0, 1024);
    sprintf(cmd, "%s\r\n", content);
    send(clientSocket, cmd, strlen(cmd), 0);
    memset(cmd, 0, 1024);
    sprintf(cmd, ".\r\n");
    send(clientSocket, cmd, strlen(cmd), 0);
    recv(clientSocket, cmd, 1024, 0);
    printf("%s\n", cmd);

    // Close socket
    close(clientSocket);

    printf("%s\n", "Email sent successfully! Try checking your inbox now!");

    return 0;
}