//Falcon-180B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 1024
#define PORT 8080
#define SA struct sockaddr

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // Set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        puts("gethostbyname error");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to server");

    // Receive data from server
    while (1) {
        bzero(buffer, MAX);
        ret = read(sockfd, buffer, MAX);
        if (ret < 0) {
            perror("read failed");
            exit(EXIT_FAILURE);
        }

        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}