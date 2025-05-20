//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in serverAddr;
    int sockfd;
    int port;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(21); // Default FTP port
    port = htons(atoi(argv[1])); // Use provided server port
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]); // Convert server IP to network address

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    // Login to server
    char username[BUF_SIZE] = "anonymous";
    char password[BUF_SIZE] = "anonymous";
    if (send(sockfd, "USER ", sizeof("USER "), 0) == -1) {
        perror("Error sending USER command");
        return 1;
    }
    if (send(sockfd, username, sizeof(username), 0) == -1) {
        perror("Error sending username");
        return 1;
    }
    if (send(sockfd, "PASS ", sizeof("PASS "), 0) == -1) {
        perror("Error sending PASS command");
        return 1;
    }
    if (send(sockfd, password, sizeof(password), 0) == -1) {
        perror("Error sending password");
        return 1;
    }

    // Change to remote directory
    char dir[] = "."; // Current directory
    if (send(sockfd, "CWD ", sizeof("CWD "), 0) == -1) {
        perror("Error sending CWD command");
        return 1;
    }
    if (send(sockfd, dir, sizeof(dir), 0) == -1) {
        perror("Error sending directory name");
        return 1;
    }

    // List files in directory
    char filename[] = "NLST"; // List command
    if (send(sockfd, filename, sizeof(filename), 0) == -1) {
        perror("Error sending NLST command");
        return 1;
    }

    // Receive file listing
    char buffer[BUF_SIZE];
    int count = recv(sockfd, buffer, sizeof(buffer), 0);
    while (count > 0) {
        printf("%s\n", buffer);
        count = recv(sockfd, buffer, sizeof(buffer), 0);
    }

    // Download a file
    char fileName[] = "index.html"; // Name of the file to download
    if (send(sockfd, "RETR ", sizeof("RETR "), 0) == -1) {
        perror("Error sending RETR command");
        return 1;
    }
    if (send(sockfd, fileName, sizeof(fileName), 0) == -1) {
        perror("Error sending file name");
        return 1;
    }

    // Receive the file
    char* downloadedFile = malloc(BUF_SIZE);
    int bytesReceived = recv(sockfd, downloadedFile, BUF_SIZE, 0);
    printf("Received %d bytes\n", bytesReceived);

    // Close the socket and free memory
    close(sockfd);
    free(downloadedFile);

    return 0;
}