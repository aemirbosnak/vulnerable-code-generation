//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFLEN 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFLEN];
    char *host = "www.google.com";

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // HTTP port

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s\n", host);
    printf("Enter the URL to fetch (e.g., /): ");
    scanf("%s", buffer);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buffer, BUFLEN, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Response from server: %s\n", buffer);

    close(sockfd);
    return 0;
}