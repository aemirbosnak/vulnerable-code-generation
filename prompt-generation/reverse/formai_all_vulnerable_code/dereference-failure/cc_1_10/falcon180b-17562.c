//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define MAX 1000

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, j, n;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char *message = "Elementary, my dear Watson!";
    int len = strlen(message);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname("127.0.0.1");
    if (server == NULL) {
        printf("Error getting host by name\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    portno = htons(atoi(PORT));
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");
    send(sockfd, message, len, 0);

    while (1) {
        bzero(buffer, MAX);
        n = recv(sockfd, buffer, MAX, 0);
        if (n < 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}