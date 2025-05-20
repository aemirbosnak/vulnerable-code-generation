//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void connectToFTPServer(int *sockfd, struct sockaddr_in *server) {
    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd < 0) error("Cannot open socket");

    memset(server, 0, sizeof(struct sockaddr_in));
    server->sin_family = AF_INET;
    server->sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to your FTP server's IP address
    server->sin_port = htons(PORT);

    if (connect(*sockfd, (struct sockaddr *)server, sizeof(*server)) < 0) {
        error("Connection failed");
    }
    printf("Connected to FTP server!\n");
}

void sendCommand(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
}

void receiveResponse(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesRead = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytesRead] = '\0';
    printf("Server Response: %s\n", buffer);
}

void login(int sockfd) {
    char username[50], password[50];
    printf("Enter FTP username: ");
    scanf("%s", username);
    printf("Enter FTP password: ");
    scanf("%s", password);

    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    sendCommand(sockfd, command);
    receiveResponse(sockfd);

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    sendCommand(sockfd, command);
    receiveResponse(sockfd);
}

void listFiles(int sockfd) {
    sendCommand(sockfd, "PASV\r\n");
    receiveResponse(sockfd);
    sendCommand(sockfd, "LIST\r\n");
    receiveResponse(sockfd);
}

void getFile(int sockfd) {
    char filename[50];
    printf("Enter filename to retrieve: ");
    scanf("%s", filename);

    sendCommand(sockfd, "RETR ");
    sendCommand(sockfd, filename);
    sendCommand(sockfd, "\r\n");
    receiveResponse(sockfd);
}

void putFile(int sockfd) {
    char filename[50];
    printf("Enter filename to upload: ");
    scanf("%s", filename);

    sendCommand(sockfd, "STOR ");
    sendCommand(sockfd, filename);
    sendCommand(sockfd, "\r\n");
    receiveResponse(sockfd);
}

void closeConnection(int sockfd) {
    sendCommand(sockfd, "QUIT\r\n");
    receiveResponse(sockfd);
    close(sockfd);
    printf("Disconnected from FTP server.\n");
}

int main() {
    int sockfd;
    struct sockaddr_in server;

    connectToFTPServer(&sockfd, &server);
    login(sockfd);
    while (1) {
        printf("\nFTP Client Menu:\n");
        printf("1. List Files\n");
        printf("2. Get File\n");
        printf("3. Put File\n");
        printf("4. Quit\n");
        printf("Choose an option: ");

        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                listFiles(sockfd);
                break;
            case 2:
                getFile(sockfd);
                break;
            case 3:
                putFile(sockfd);
                break;
            case 4:
                closeConnection(sockfd);
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    return 0;
}