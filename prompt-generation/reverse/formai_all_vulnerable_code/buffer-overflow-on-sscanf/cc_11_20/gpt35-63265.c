//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in pop3_server;
    char buf[BUFSIZE];
    char user[64], pass[64];
    int msg_count, msg_size;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <POP3 server> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to POP3 server
    pop3_server.sin_family = AF_INET;
    pop3_server.sin_port = htons(110);
    if (inet_pton(AF_INET, argv[1], &pop3_server.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    if (connect(sock, (struct sockaddr *) &pop3_server, sizeof(pop3_server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Get server greeting
    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("SERVER: %s", buf);

    // Send username
    printf("Enter POP3 username: ");
    scanf("%s", user);
    sprintf(buf, "USER %s\r\n", user);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("SERVER: %s", buf);

    // Send password
    printf("Enter POP3 password: ");
    scanf("%s", pass);
    sprintf(buf, "PASS %s\r\n", pass);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("SERVER: %s", buf);

    // Get number of messages and total size
    sprintf(buf, "STAT\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    sscanf(buf, "+OK %d %d", &msg_count, &msg_size);
    printf("SERVER: %s", buf);

    // Get list of messages
    sprintf(buf, "LIST\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    printf("MESSAGES:\n");
    while (recv(sock, buf, BUFSIZE, 0) > 0) {
        if (strncmp(buf, ".", 1) == 0) {
            break;
        }
        printf("%s", buf);
    }

    // Quit
    sprintf(buf, "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sock, buf, BUFSIZE, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("SERVER: %s", buf);

    close(sock);
    exit(EXIT_SUCCESS);
}