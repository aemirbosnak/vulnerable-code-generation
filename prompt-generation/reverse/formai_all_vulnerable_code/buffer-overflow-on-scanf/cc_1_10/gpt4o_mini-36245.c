//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define FTP_PORT 21
#define MAX_RETRIES 3

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void sendCommand(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Send failed");
    }
}

void receiveResponse(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) error("Receive failed");
    buffer[n] = '\0';
    printf("%s", buffer);
}

void connectToFTPServer(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Socket creation failed");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(FTP_PORT);
    
    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    receiveResponse(sockfd);
    
    // Sending login credentials
    sendCommand(sockfd, "USER anonymous\r\n");
    receiveResponse(sockfd);
    sendCommand(sockfd, "PASS anonymous\r\n");
    receiveResponse(sockfd);
    
    // Do a list command
    sendCommand(sockfd, "LIST\r\n");
    receiveResponse(sockfd);

    close(sockfd);
}

void printMenu() {
    printf("\n--- Welcome to the FTP Client! ---\n");
    printf("1. Connect to FTP Server\n");
    printf("2. Exit\n");
    printf("Please select an option: ");
}

int main() {
    char hostname[100];
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter hostname or IP address: ");
                scanf("%s", hostname);
                connectToFTPServer(hostname);
                break;
            case 2:
                printf("Exiting the FTP Client. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}