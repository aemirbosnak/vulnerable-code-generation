//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char msg[MAX_MSG_SIZE];
    char *server_name;
    int server_port;
    int n;

    if (argc!= 4) {
        printf("Usage:./client <server_name> <server_port> <message>\n");
        exit(1);
    }

    server_name = argv[1];
    server_port = atoi(argv[2]);
    strcpy(msg, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_name, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server.\n");

    send(sockfd, msg, strlen(msg), 0);

    while ((n = recv(sockfd, msg, MAX_MSG_SIZE, 0)) > 0) {
        msg[n] = '\0';
        printf("Received message: %s\n", msg);
    }

    close(sockfd);
    exit(0);
}