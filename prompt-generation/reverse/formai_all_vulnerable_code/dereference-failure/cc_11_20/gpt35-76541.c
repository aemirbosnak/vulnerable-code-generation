//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define IMAP_PORT 143

int main(int argc, char **argv) {
    int sock_fd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // Resolve hostname to IP address
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Receive greeting from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send login command
    sprintf(buffer, "LOGIN %s\r\n", argv[2]);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive login response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send list command
    if (send(sock_fd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive list response(s)
    memset(buffer, 0, sizeof(buffer));
    while (recv(sock_fd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // Send select command
    if (send(sock_fd, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive select response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Send fetch command
    if (send(sock_fd, "FETCH 1 BODY[TEXT]\r\n", strlen("FETCH 1 BODY[TEXT]\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive fetch response
    memset(buffer, 0, sizeof(buffer));
    while (recv(sock_fd, buffer, sizeof(buffer), 0) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // Send logout command
    if (send(sock_fd, "LOGOUT\r\n", strlen("LOGOUT\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive logout response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sock_fd);

    return 0;
}