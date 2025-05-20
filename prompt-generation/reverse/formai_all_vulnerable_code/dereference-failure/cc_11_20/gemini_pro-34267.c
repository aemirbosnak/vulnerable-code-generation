//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define CHUNK_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char* cmd = "USER anonymous\n";
    if (send(sockfd, cmd, strlen(cmd), 0) != strlen(cmd)) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char* resp = malloc(CHUNK_SIZE);
    if (recv(sockfd, resp, CHUNK_SIZE, 0) == -1) {
        fprintf(stderr, "recv() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s", resp);

    cmd = "PASS test@example.com\n";
    if (send(sockfd, cmd, strlen(cmd), 0) != strlen(cmd)) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (recv(sockfd, resp, CHUNK_SIZE, 0) == -1) {
        fprintf(stderr, "recv() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    printf("%s", resp);

    cmd = "LIST\n";
    if (send(sockfd, cmd, strlen(cmd), 0) != strlen(cmd)) {
        fprintf(stderr, "send() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while (1) {
        if (recv(sockfd, resp, CHUNK_SIZE, 0) == -1) {
            fprintf(stderr, "recv() failed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        if (strcmp(resp, "226 Transfer complete.\n") == 0) {
            break;
        }
        printf("%s", resp);
    }

    close(sockfd);
    return 0;
}