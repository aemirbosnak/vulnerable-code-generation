//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    int sock_fd, port_no, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];

    port_no = 110;

    if (argc < 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(0);
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    serv_addr.sin_port = htons(port_no);

    if (connect(sock_fd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    n = read(sock_fd, buffer, BUFSIZE);

    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    bzero(buffer, BUFSIZE);

    snprintf(buffer, BUFSIZE, "USER %s\r\n", "your_username");

    n = write(sock_fd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, BUFSIZE);

    n = read(sock_fd, buffer, BUFSIZE);

    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    bzero(buffer, BUFSIZE);

    snprintf(buffer, BUFSIZE, "PASS %s\r\n", "your_password");

    n = write(sock_fd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, BUFSIZE);

    n = read(sock_fd, buffer, BUFSIZE);

    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    bzero(buffer, BUFSIZE);

    snprintf(buffer, BUFSIZE, "LIST\r\n");

    n = write(sock_fd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, BUFSIZE);

    n = read(sock_fd, buffer, BUFSIZE);

    if (n < 0) {
        fprintf(stderr, "ERROR reading from socket\n");
        exit(1);
    }

    printf("%s\n", buffer);

    bzero(buffer, BUFSIZE);

    snprintf(buffer, BUFSIZE, "QUIT\r\n");

    n = write(sock_fd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    close(sock_fd);

    return 0;
}