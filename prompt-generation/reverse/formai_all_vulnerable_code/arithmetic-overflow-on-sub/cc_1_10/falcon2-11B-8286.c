//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to create a TCP socket
int createSocket(int port) {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }
    return sockfd;
}

// Function to connect to a server
int connectToServer(int sockfd, const char* serverIP, int serverPort) {
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    inet_pton(AF_INET, serverIP, &serverAddress.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection error");
        exit(1);
    }
    return sockfd;
}

// Function to send data to server
int sendData(int sockfd, const char* data) {
    int numBytesSent = 0;
    while (numBytesSent < strlen(data)) {
        int bytesSent = send(sockfd, data + numBytesSent, strlen(data) - numBytesSent, 0);
        if (bytesSent < 0) {
            perror("Send data error");
            exit(1);
        }
        numBytesSent += bytesSent;
    }
    return numBytesSent;
}

// Function to receive data from server
int receiveData(int sockfd, char* buffer, int bufferSize) {
    int numBytesReceived = 0;
    while (numBytesReceived < bufferSize) {
        int bytesReceived = recv(sockfd, buffer + numBytesReceived, bufferSize - numBytesReceived, 0);
        if (bytesReceived < 0) {
            perror("Receive data error");
            exit(1);
        }
        numBytesReceived += bytesReceived;
    }
    return numBytesReceived;
}

int main() {
    int sockfd;
    int port = 8080;

    sockfd = createSocket(port);
    if (sockfd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);

    sockfd = connectToServer(sockfd, "127.0.0.1", port);
    if (sockfd < 0) {
        perror("Connection error");
        exit(1);
    }

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    sendData(sockfd, "Hello, server!\n");
    printf("Received: %s\n", buffer);
    receiveData(sockfd, buffer, sizeof(buffer));
    printf("Sent: %s\n", buffer);

    close(sockfd);
    return 0;
}