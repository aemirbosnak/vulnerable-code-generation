//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <IP address> <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n == 0) {
            printf("Disconnected from server\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}