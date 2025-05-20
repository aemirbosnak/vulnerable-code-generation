//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int n;

    printf("Enter the server address: ");
    scanf("%s", buffer);

    portno = atoi(buffer);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, "localhost", &serv_addr.sin_addr) <= 0) {
        perror("ERROR: invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Sending message...\n");
    n = write(sockfd, "Hello, World!\n", 13);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    printf("Receiving message...\n");
    n = read(sockfd, buffer, 256);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    close(sockfd);
    return 0;
}