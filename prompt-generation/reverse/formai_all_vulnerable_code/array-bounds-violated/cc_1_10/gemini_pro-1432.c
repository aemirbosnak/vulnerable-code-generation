//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110

void receive_response(int sockfd) {
    char buffer[1024];
    int bytes_received;

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    if (bytes_received < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    receive_response(sockfd);

    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);
    receive_response(sockfd);

    snprintf(buffer, sizeof(buffer), "PASS\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive_response(sockfd);

    snprintf(buffer, sizeof(buffer), "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive_response(sockfd);

    snprintf(buffer, sizeof(buffer), "RETR\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive_response(sockfd);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    receive_response(sockfd);

    close(sockfd);

    return EXIT_SUCCESS;
}