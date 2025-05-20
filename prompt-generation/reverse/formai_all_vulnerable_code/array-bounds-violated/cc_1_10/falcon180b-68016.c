//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;

    printf("POP3 client starting...\n");

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    printf("Socket created\n");

    // Set server address
    portno = 110;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    // Send user name
    sprintf(buffer, "USER %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send password
    sprintf(buffer, "PASS %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive server response
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Server response: %s", buffer);

    // Close socket
    close(sockfd);

    printf("POP3 client finished.\n");

    return 0;
}