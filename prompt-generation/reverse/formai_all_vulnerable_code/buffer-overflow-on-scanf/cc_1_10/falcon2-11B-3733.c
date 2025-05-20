//Falcon2-11B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUF_SIZE];

    printf("Enter the IP address of the server: ");
    scanf("%s", &buffer);

    server = gethostbyname(buffer);
    if (server == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    portno = htons(5000);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, MAX_BUF_SIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Wi-Fi signal strength: %d\n", atoi(buffer));
    }

    return 0;
}