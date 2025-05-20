//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

void handle_command(int sockfd, char* command) {
    char reply[256];
    int n;

    printf("> %s\n", command);
    send(sockfd, command, strlen(command), 0);

    memset(reply, 0, sizeof(reply));
    n = recv(sockfd, reply, sizeof(reply) - 1, 0);
    reply[n] = '\0';
    printf("FTP server: %s\n", reply);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[256];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        printf("FTP> ");
        fgets(buffer, sizeof(buffer), stdin);
        handle_command(sockfd, buffer);
    }

    close(sockfd);
    return 0;
}