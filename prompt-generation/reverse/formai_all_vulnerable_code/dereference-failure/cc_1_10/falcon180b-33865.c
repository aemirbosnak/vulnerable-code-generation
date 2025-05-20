//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *username = "your_username";
    char *password = "your_password";
    char *server = "pop.gmail.com";
    int server_port = 110;

    if (argc < 3) {
        printf("Usage:./pop3_client <server_address> <port_number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    printf("Connected to POP3 server.\n");

    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "STAT\r\n", 6, 0);

    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "QUIT\r\n", 6, 0);

    close(sockfd);
    return 0;
}