//Falcon-180B DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in seraddr, cliaddr;
    char buffer[BUFFER_SIZE];
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(1);
    }

    printf("Enter the server's IP address: ");
    scanf("%s", buffer);

    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    // Fill server address structure
    bcopy((char *)server->h_addr, (char *)&seraddr.sin_addr.s_addr, server->h_length);
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(12345);

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to the server\n");

    // Receive messages from server
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        ret = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (ret == 0) {
            printf("Disconnected from the server\n");
            close(sockfd);
            exit(0);
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}