//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "12345"
#define MAX 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen, len;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error: No such host");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX);
        len = read(sockfd, buffer, MAX);
        if (len < 0) {
            printf("Error reading from socket");
            exit(1);
        }
        if (len == 0) {
            printf("Connection closed by server\n");
            exit(0);
        }
        buffer[len] = '\0';
        printf("Received message: %s\n", buffer);
    }

    return 0;
}