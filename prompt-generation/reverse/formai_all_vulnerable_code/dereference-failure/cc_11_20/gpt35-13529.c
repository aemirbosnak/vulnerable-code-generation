//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
    int sock_fd, port_no, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
       printf("Usage: %s server_address port_number\n", argv[0]);
       exit(1);
    }

    port_no = atoi(argv[2]);
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error: Cannot open socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: No such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_no);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    if (connect(sock_fd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error: Cannot connect to server");
        exit(1);
    }

    // perform login
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s%s\r\n", "LOGIN ", "<username> <password>");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: Cannot write to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error: Cannot read from socket");
        exit(1);
    }

    if (strstr(buffer, "BAD") != NULL) {
        perror("Error: Login failed");
        exit(1);
    }

    // select mailbox
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "SELECT <mailbox>");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: Cannot write to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error: Cannot read from socket");
        exit(1);
    }

    if (strstr(buffer, "BAD") != NULL) {
        perror("Error: Cannot select mailbox");
        exit(1);
    }

    // fetch messages
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "FETCH 1:* BODY[HEADER]");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: Cannot write to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error: Cannot read from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    // logout
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "%s\r\n", "LOGOUT");
    n = write(sock_fd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: Cannot write to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sock_fd, buffer, BUF_SIZE);
    if (n < 0) {
        perror("Error: Cannot read from socket");
        exit(1);
    }

    if (strstr(buffer, "BYE") == NULL) {
        perror("Error: Logout failed");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sock_fd);

    return 0;
}