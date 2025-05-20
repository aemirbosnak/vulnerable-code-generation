//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <Server IP> <Server Port>\n", argv[0]);
        return 1;
    }

    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Failed to create socket");
        return 2;
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
    serverAddress.sin_port = htons(atoi(argv[2]));

    if (connect(clientSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress)) == -1) {
        perror("Failed to connect to server");
        close(clientSocket);
        return 3;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive banner message from server");
        close(clientSocket);
        return 4;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "HELO client.example.com\r\n");
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send HELO message to server");
        close(clientSocket);
        return 5;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive welcome message from server");
        close(clientSocket);
        return 6;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    printf("Enter sender email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* sender = strtok(buffer, "\n");

    memset(buffer, 0, sizeof(buffer));
    printf("Enter recipient email address: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* recipient = strtok(buffer, "\n");

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send MAIL FROM message to server");
        close(clientSocket);
        return 7;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive sender OK response from server");
        close(clientSocket);
        return 8;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send RCPT TO message to server");
        close(clientSocket);
        return 9;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive recipient OK response from server");
        close(clientSocket);
        return 10;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "DATA\r\n");
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send DATA message to server");
        close(clientSocket);
        return 11;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive data OK response from server");
        close(clientSocket);
        return 12;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    printf("Enter email subject: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* subject = strtok(buffer, "\n");

    memset(buffer, 0, sizeof(buffer));
    printf("Enter email message:\n");
    fgets(buffer, BUFFER_SIZE, stdin);
    char* message = strtok(buffer, "\n");

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "Subject:%s\r\n\r\n%s\r\n.\r\n", subject, message);
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send email message to server");
        close(clientSocket);
        return 13;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive message sent OK response from server");
        close(clientSocket);
        return 14;
    }
    printf("Server: %s", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "QUIT\r\n");
    if (send(clientSocket, buffer, strlen(buffer), 0) == -1) {
        perror("Failed to send QUIT message to server");
        close(clientSocket);
        return 15;
    }

    if (recv(clientSocket, buffer, sizeof(buffer), 0) == -1) {
        perror("Failed to receive quit OK response");
        close(clientSocket);
        return 16;
    }
    printf("Server: %s", buffer);

    close(clientSocket);
    return 0;
}