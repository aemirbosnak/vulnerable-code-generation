//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    // Declare variables
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct hostent *hostinfo;
    char username[64];
    char password[64];
    char userCommand[BUFFER_SIZE] = { 0 };
    char serverResponse[BUFFER_SIZE] = { 0 };

    // Get user input
    printf("Enter POP3 server hostname: ");
    scanf("%s", buffer);
    hostinfo = gethostbyname(buffer);
    if (hostinfo == NULL) {
        perror("Error getting hostname.");
        exit(1);
    }

    // Create socket for communication with server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket.");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr*) & server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("Error connecting to server.");
        exit(1);
    }

    // Receive greeting message from server
    memset(buffer, 0, BUFFER_SIZE);
    ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving greeting message.");
        exit(1);
    }
    printf("%s", buffer); // Print greeting message

    // Send username to server
    printf("Enter username: ");
    scanf("%s", username);
    sprintf(userCommand, "USER %s\n", username);
    ret = send(sockfd, userCommand, strlen(userCommand), 0);
    if (ret < 0) {
        perror("Error sending username.");
        exit(1);
    }

    // Receive response from server
    memset(serverResponse, 0, BUFFER_SIZE);
    ret = recv(sockfd, serverResponse, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving response.");
        exit(1);
    }
    printf("%s", serverResponse); // Print response from server

    // Send password to server
    printf("Enter password: ");
    scanf("%s", password);
    sprintf(userCommand, "PASS %s\n", password);
    ret = send(sockfd, userCommand, strlen(userCommand), 0);
    if (ret < 0) {
        perror("Error sending password.");
        exit(1);
    }

    // Receive response from server
    memset(serverResponse, 0, BUFFER_SIZE);
    ret = recv(sockfd, serverResponse, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving response.");
        exit(1);
    }
    printf("%s", serverResponse); // Print response from server

    // Send QUIT command to server
    ret = send(sockfd, "QUIT\n", 5, 0);
    if (ret < 0) {
        perror("Error sending QUIT command.");
        exit(1);
    }

    // Receive response from server
    memset(serverResponse, 0, BUFFER_SIZE);
    ret = recv(sockfd, serverResponse, BUFFER_SIZE, 0);
    if (ret < 0) {
        perror("Error receiving response.");
        exit(1);
    }
    printf("%s", serverResponse); // Print response from server

    // Close socket
    close(sockfd);

    return 0;
}