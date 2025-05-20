//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110
#define BUFFER_SIZE 1024

int main(void) {
    int sockfd, numbytes;
    struct sockaddr_in server;

    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("POP3 Client\n");
    printf("Username: ");
    scanf("%s", buffer);
    printf("Password: ");
    scanf("%s", buffer);

    numbytes = send(sockfd, buffer, strlen(buffer), 0);

    if (numbytes < 0) {
        perror("send");
        exit(1);
    }

    numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (numbytes < 0) {
        perror("recv");
        exit(1);
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);

    return 0;
}