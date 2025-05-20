//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
/* Romeo and Juliet - A POP3 Client Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_BUFFER 1024

// Declarations
char* username = "romeo@verona.com";
char* password = "juliet";
char* serverIP = "127.0.0.1";
int serverPort = 110;
char buffer[MAX_BUFFER];
int sockfd;

// Connect to the server
bool connectToServer() {
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        return false;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(serverIP);
    server_addr.sin_port = htons(serverPort);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        return false;
    }

    printf("Connected to POP3 server\n");
    recv(sockfd, buffer, MAX_BUFFER, 0);

    printf("Server message: %s\n", buffer);
    return true;
}

// Authenticate the user
bool authenticateUser() {
    char loginCommand[MAX_BUFFER], authBuffer[MAX_BUFFER];
    sprintf(loginCommand, "USER %s\r\n", username);
    send(sockfd, loginCommand, strlen(loginCommand), 0);
    recv(sockfd, authBuffer, MAX_BUFFER, 0);

    printf("Server message: %s\n", authBuffer);

    char passCommand[MAX_BUFFER];
    sprintf(passCommand, "PASS %s\r\n", password);
    send(sockfd, passCommand, strlen(passCommand), 0);
    recv(sockfd, authBuffer, MAX_BUFFER, 0);

    printf("Server message: %s\n", authBuffer);

    if(strncmp(authBuffer, "+OK", 3) == 0) {
        return true;
    } else {
        return false;
    }
}

// Get the list of emails
void getEmailList() {
    char listCommand[MAX_BUFFER];
    sprintf(listCommand, "LIST\r\n");
    send(sockfd, listCommand, strlen(listCommand), 0);
    recv(sockfd, buffer, MAX_BUFFER, 0);

    printf("Server message: %s\n", buffer);
}

// Get the details of the selected email
void getEmail(int emailNumber) {
    char retrCommand[MAX_BUFFER];
    sprintf(retrCommand, "RETR %d\r\n", emailNumber);
    send(sockfd, retrCommand, strlen(retrCommand), 0);

    while(recv(sockfd, buffer, MAX_BUFFER, 0) > 0) {
        printf("%s", buffer);
    }

    printf("\n");
}

int main() {
    bool isConnected = connectToServer();

    if(isConnected) {
        bool isAuth = authenticateUser();

        if(isAuth) {
            getEmailList();

            printf("Which message do you want to read? (Enter number)\n");
            int emailNumber;
            scanf("%d", &emailNumber);
            getEmail(emailNumber);
        } else {
            printf("Invalid username or password\n");
        }
    } else {
        printf("Could not connect to POP3 server\n");
    }

    close(sockfd);

    return 0;
}