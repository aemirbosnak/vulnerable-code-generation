//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
    };

    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Invalid host: %s\n", host);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    if (fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    int bytes_sent = send(sockfd, command, strlen(command), 0);
    if (bytes_sent == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    while (1) {
        int bytes_received = 0;
        do {
            bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1 && errno == EAGAIN) {
                sleep(1);
            } else if (bytes_received == 0) {
                break;
            } else if (bytes_received < 0) {
                perror("recv");
                return EXIT_FAILURE;
            }
            write(1, buffer, bytes_received);
        } while (bytes_received > 0);

        if (bytes_received == 0) {
            break;
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}