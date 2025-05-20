//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s server_ip server_port\n", argv[0]);
        return 1;
    }

    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_aton(server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    printf("Connected to server %s:%d\n", server_ip, server_port);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        printf("> ");

        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;
        }

        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        if (strcmp(buffer, "quit") == 0 || strcmp(buffer, "exit") == 0) {
            break;
        }

        ssize_t written = write(sockfd, buffer, strlen(buffer));
        if (written == -1) {
            perror("write");
            return 1;
        }

        ssize_t bytes_read = read(sockfd, buffer, BUFFER_SIZE);
        if (bytes_read == -1) {
            perror("read");
            return 1;
        }

        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    printf("Disconnected from server.\n");

    return 0;
}