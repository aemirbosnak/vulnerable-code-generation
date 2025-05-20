//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s [server] [username] [password]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char response[BUFSIZE];
    char buf[BUFSIZE];
    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    int sock_fd, ret;
    struct sockaddr_in serv_addr;

    sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110); // POP3 port
    if (inet_pton(AF_INET, server, &serv_addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(struct sockaddr_in)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read server response
    ret = read(sock_fd, response, BUFSIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Server closed the connection\n");
        exit(EXIT_FAILURE);
    }
    response[ret] = '\0';
    printf("%s", response);

    // Send username
    snprintf(buf, BUFSIZE, "USER %s\r\n", username);
    if (write(sock_fd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    ret = read(sock_fd, response, BUFSIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Server closed the connection\n");
        exit(EXIT_FAILURE);
    }
    response[ret] = '\0';
    printf("%s", response);

    // Send password
    snprintf(buf, BUFSIZE, "PASS %s\r\n", password);
    if (write(sock_fd, buf, strlen(buf)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    ret = read(sock_fd, response, BUFSIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Server closed the connection\n");
        exit(EXIT_FAILURE);
    }
    response[ret] = '\0';
    printf("%s", response);

    // Check if authentication succeeded
    if (strncmp(response, "+OK", 3) != 0) {
        printf("Authentication failed\n");
        exit(EXIT_FAILURE);
    }

    // Get mailbox details
    if (write(sock_fd, "STAT\r\n", 6) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    ret = read(sock_fd, response, BUFSIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Server closed the connection\n");
        exit(EXIT_FAILURE);
    }
    response[ret] = '\0';
    printf("%s", response);

    // Quit
    if (write(sock_fd, "QUIT\r\n", 6) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read server response
    ret = read(sock_fd, response, BUFSIZE);
    if (ret == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Server closed the connection\n");
        exit(EXIT_FAILURE);
    }
    response[ret] = '\0';
    printf("%s", response);

    close(sock_fd);

    printf("Sherlock has solved the mystery of the mailbox\n");
    return EXIT_SUCCESS;
}