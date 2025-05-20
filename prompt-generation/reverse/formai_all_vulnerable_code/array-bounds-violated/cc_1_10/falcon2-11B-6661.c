//Falcon2-11B DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_SIZE 100

int main() {
    int sockfd, numbytes, portno, newsockfd, pid;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_SIZE];
    char server_name[] = "www.example.com";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server_name);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        bzero(buffer, MAX_SIZE);
        if ((numbytes = recv(sockfd, buffer, MAX_SIZE - 1, 0)) < 0) {
            perror("ERROR receiving");
            exit(1);
        }
        buffer[numbytes] = '\0';

        printf("Received: %s\n", buffer);

        bzero(buffer, MAX_SIZE);
        if ((numbytes = send(sockfd, buffer, strlen(buffer), 0)) < 0) {
            perror("ERROR sending");
            exit(1);
        }
    }

    return 0;
}