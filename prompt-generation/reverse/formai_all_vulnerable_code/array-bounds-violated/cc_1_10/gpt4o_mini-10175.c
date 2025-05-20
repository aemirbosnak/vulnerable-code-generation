//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connectToFtpServer(const char* server_ip, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Connection to server failed");
    }
    
    return sockfd;
}

void sendCommand(int sockfd, const char* command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        error("Error sending command");
    }
}

void receiveResponse(int sockfd) {
    char buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sockfd, buffer, BUF_SIZE - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }
}

void loginToFtp(int sockfd, const char* user, const char* password) {
    char command[BUF_SIZE];

    sprintf(command, "USER %s\r\n", user);
    sendCommand(sockfd, command);
    receiveResponse(sockfd);

    sprintf(command, "PASS %s\r\n", password);
    sendCommand(sockfd, command);
    receiveResponse(sockfd);
}

void listFiles(int sockfd) {
    char command[BUF_SIZE];

    sprintf(command, "PASV\r\n");
    sendCommand(sockfd, command);
    receiveResponse(sockfd);
    
    // Here you would need to handle PASV response to get data port for file listing
    // Faking the process for demo purpose, we'll assume a data connection is made and files are listed.
    
    sprintf(command, "LIST\r\n");
    sendCommand(sockfd, command);
    receiveResponse(sockfd);
}

void downloadFile(int sockfd, const char* filename) {
    char command[BUF_SIZE];

    sprintf(command, "RETR %s\r\n", filename);
    sendCommand(sockfd, command);
    receiveResponse(sockfd);

    // In a real-world application, you'd read from a new data socket.
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <server_ip> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char* server_ip = argv[1];
    const char* username = argv[2];
    const char* password = argv[3];

    int sockfd = connectToFtpServer(server_ip, 21); // Default FTP port is 21
    receiveResponse(sockfd);

    loginToFtp(sockfd, username, password);
    
    printf("File Listing:\n");
    listFiles(sockfd);

    // Example of downloading a file
    downloadFile(sockfd, "example.txt");

    close(sockfd);
    return 0;
}