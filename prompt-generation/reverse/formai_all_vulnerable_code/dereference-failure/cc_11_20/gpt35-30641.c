//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock_fd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUF_SIZE];
    int n;

    if (argc < 3) {
       fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
       exit(0);
    }

    /* create socket */
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket.\n");
        exit(1);
    }

    /* get server by hostname */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host.\n");
        exit(2);
    }

    /* build server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    /* connect to server */
    if (connect(sock_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting.\n");
        exit(1);
    }

    /* read initial response */
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    /* login */
    sprintf(buffer, "A1 LOGIN USERNAME PASSWORD\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.\n");
        exit(1);
    }

    /* read login response */
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    /* select INBOX */
    sprintf(buffer, "A2 SELECT INBOX\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.\n");
        exit(1);
    }

    /* read select response */
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    /* logout */
    sprintf(buffer, "A3 LOGOUT\r\n");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket.\n");
        exit(1);
    }

    /* read logout response */
    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket.\n");
        exit(1);
    }
    printf("%s", buffer);

    close(sock_fd);
    exit(0);
}