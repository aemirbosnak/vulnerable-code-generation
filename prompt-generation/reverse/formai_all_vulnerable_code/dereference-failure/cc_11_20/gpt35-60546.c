//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_LINE_SIZE 1024
#define MAX_SEND_SIZE 4096

int main(int argc, char** argv) {
    char* server_address;
    char* username;
    char* password;

    if (argc < 4) {
        fprintf(stderr, "USAGE: %s <server_address> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_address = argv[1];
    username = argv[2];
    password = argv[3];

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct hostent* host = gethostbyname(server_address);

    if (!host) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr = *((struct in_addr*) host->h_addr_list[0]);

    if (connect(sock_fd, (struct sockaddr*) &server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_SIZE];

    int n_bytes = recv(sock_fd, line, MAX_LINE_SIZE - 1, 0);

    if (n_bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    line[n_bytes] = '\0';

    if (strncmp("+ OK", line, 4) != 0) {
        fprintf(stderr, "IMAP server did not respond to connection request with + OK\n");
        exit(EXIT_FAILURE);
    }

    sprintf(line, "1 LOGIN %s %s\r\n", username, password);

    if (send(sock_fd, line, strlen(line), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    n_bytes = recv(sock_fd, line, MAX_LINE_SIZE - 1, 0);

    if (n_bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    line[n_bytes] = '\0';

    if (strncmp("1 OK", line, 4) != 0) {
        fprintf(stderr, "IMAP server did not respond to LOGIN request with 1 OK\n");
        exit(EXIT_FAILURE);
    }

    sprintf(line, "2 LIST \"\" *\r\n");

    if (send(sock_fd, line, strlen(line), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    n_bytes = recv(sock_fd, line, MAX_LINE_SIZE - 1, 0);

    if (n_bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    line[n_bytes] = '\0';

    if (strncmp("2 OK", line, 4) != 0) {
        fprintf(stderr, "IMAP server did not respond to LIST request with 2 OK\n");
        exit(EXIT_FAILURE);
    }

    sprintf(line, "3 SELECT INBOX\r\n");

    if (send(sock_fd, line, strlen(line), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    n_bytes = recv(sock_fd, line, MAX_LINE_SIZE - 1, 0);

    if (n_bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    line[n_bytes] = '\0';

    if (strncmp("3 OK", line, 4) != 0) {
        fprintf(stderr, "IMAP server did not respond to SELECT request with 3 OK\n");
        exit(EXIT_FAILURE);
    }

    sprintf(line, "4 FETCH 1 BODY[HEADER]\r\n");

    if (send(sock_fd, line, strlen(line), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    n_bytes = recv(sock_fd, line, MAX_LINE_SIZE - 1, 0);

    if (n_bytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    line[n_bytes] = '\0';

    if (strncmp("4 OK", line, 4) != 0) {
        fprintf(stderr, "IMAP server did not respond to FETCH request with 4 OK\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", line);

    if (close(sock_fd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}