//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <pop3_server_address> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *pop3_server_address = argv[1];
    char *username = argv[2];

    struct hostent *he = gethostbyname(pop3_server_address);
    if (he == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    char *pop3_server_ip_address = inet_ntoa(*addr_list[0]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = { 0 };
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(pop3_server_ip_address);

    int connected = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (connected == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE] = { 0 };
    ssize_t bytes_received = read(sockfd, buf, BUF_SIZE - 1);
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buf[bytes_received] = '\0';

    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "USER %s\r\n", username);
    ssize_t bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = read(sockfd, buf, BUF_SIZE - 1);
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buf[bytes_received] = '\0';

    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "PASS ");
    char *password = getpass("Enter password: ");
    strncat(buf, password, BUF_SIZE - strlen(buf));
    strncat(buf, "\r\n", BUF_SIZE - strlen(buf));

    bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = read(sockfd, buf, BUF_SIZE - 1);
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buf[bytes_received] = '\0';

    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "LIST\r\n");

    bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = read(sockfd, buf, BUF_SIZE - 1);
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buf[bytes_received] = '\0';

    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "QUIT\r\n");

    bytes_sent = send(sockfd, buf, strlen(buf), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = read(sockfd, buf, BUF_SIZE - 1);
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    buf[bytes_received] = '\0';

    printf("%s", buf);

    int closed = close(sockfd);
    if (closed == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}