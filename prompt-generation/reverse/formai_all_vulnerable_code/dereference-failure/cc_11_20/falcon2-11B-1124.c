//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 110

int main() {
    int socket_fd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buf[1024];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    if (send(socket_fd, "USER username\r\n", 15, 0) < 0) {
        perror("ERROR sending USER command");
        exit(EXIT_FAILURE);
    }

    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    if (send(socket_fd, "PASS password\r\n", 15, 0) < 0) {
        perror("ERROR sending PASS command");
        exit(EXIT_FAILURE);
    }

    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    if (send(socket_fd, "LIST\r\n", 8, 0) < 0) {
        perror("ERROR sending LIST command");
        exit(EXIT_FAILURE);
    }

    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    if (send(socket_fd, "QUIT\r\n", 8, 0) < 0) {
        perror("ERROR sending QUIT command");
        exit(EXIT_FAILURE);
    }

    if (recv(socket_fd, buf, sizeof(buf), 0) < 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    close(socket_fd);

    return 0;
}