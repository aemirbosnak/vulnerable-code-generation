//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

// Function to send a command to server and receive response
void sendCommand(int sockFd, const char* command, char* response) {
    char buffer[MAX_LENGTH];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "%s\r\n", command);
    int len = strlen(buffer);

    if (send(sockFd, buffer, len, 0) == -1) {
        perror("Error in sending command");
        exit(1);
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(sockFd, buffer, sizeof(buffer), 0) == -1) {
        perror("Error in receiving response");
        exit(1);
    }
    strcpy(response, buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server_address> <username>\n", argv[0]);
        exit(1);
    }

    char response[MAX_LENGTH];
    char serverAddress[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char command[MAX_LENGTH];
    int port = 143;

    strcpy(serverAddress, argv[1]);
    strcpy(username, argv[2]);

    // Get IP address of the server
    struct hostent* server = gethostbyname(serverAddress);
    if (server == NULL) {
        printf("Error: No such host found\n");
        exit(1);
    }

    // Create socket
    int sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFd == -1) {
        perror("Error in creating socket");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr = *((struct in_addr*) server->h_addr);

    if (connect(sockFd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error in connecting to server");
        exit(1);
    }

    // Send login command and get response
    char* loginCommand = "LOGIN";
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(command, "%s %s %s", loginCommand, username, password);
    sendCommand(sockFd, command, response);
    printf("Response: %s", response);

    // Send select command and get response
    char* selectCommand = "SELECT INBOX";
    sendCommand(sockFd, selectCommand, response);
    printf("Response: %s", response);

    // Get mailbox status
    char* statusCommand = "STATUS INBOX (MESSAGES UNSEEN)";
    sendCommand(sockFd, statusCommand, response);
    printf("Response: %s", response);

    // Log out and close socket
    char* logoutCommand = "LOGOUT";
    sendCommand(sockFd, logoutCommand, response);
    printf("Response: %s", response);
    close(sockFd);

    return 0;
}