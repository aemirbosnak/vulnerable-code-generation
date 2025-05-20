//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    char *server;
    int port, sock;
    struct addrinfo hints, *res;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    server = argv[1];
    port = atoi(argv[2]);
    char *username = argv[3];

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve server address and port
    int gai_err;
    if ((gai_err = getaddrinfo(server, NULL, &hints, &res))!= 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(gai_err));
        return 1;
    }

    // Create socket
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Connect to server
    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    // Send USER command
    char user_cmd[20] = "USER ";
    strncat(user_cmd, username, strlen(username));
    strncat(user_cmd, "\r\n", 2);
    send(sock, user_cmd, strlen(user_cmd), 0);

    // Send PASS command
    char pass_cmd[20] = "PASS ";
    strncat(pass_cmd, username, strlen(username));
    strncat(pass_cmd, "\r\n", 2);
    send(sock, pass_cmd, strlen(pass_cmd), 0);

    // Receive server response
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}