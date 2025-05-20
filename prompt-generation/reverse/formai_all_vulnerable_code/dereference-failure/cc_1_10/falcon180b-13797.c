//Falcon-180B DATASET v1.0 Category: Networking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

// Function to print error message and exit on socket error
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./client <IP address> <port>\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        usage();
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    // Set up server address structure
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error("Error connecting to server");
    }

    printf("Connected to server\n");

    // Send and receive data
    send(sockfd, "Hello, world!", strlen("Hello, world!"), 0);
    memset(buffer, 0, BUF_SIZE);
    recv(sockfd, buffer, BUF_SIZE, 0);
    printf("Received from server: %s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}