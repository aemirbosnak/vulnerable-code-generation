//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *serverinfo;
    char hostname[100];
    char username[100];
    char password[100];
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int n;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 username: ");
    scanf("%s", username);

    printf("Enter POP3 password: ");
    scanf("%s", password);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, "pop3", &hints, &serverinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sockfd, username, strlen(username), 0) == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sockfd, "\r\n", 2, 0) == -1) {
        fprintf(stderr, "send: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received == 0) {
            fprintf(stderr, "Connection closed by server\n");
            exit(0);
        } else if (bytes_received == -1) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
            exit(1);
        }

        buffer[bytes_received] = '\0';

        for (n = 0; n < bytes_received; n++) {
            if (buffer[n] == '\n') {
                printf("%s", buffer);
                break;
            }
        }
    }

    close(sockfd);

    return 0;
}