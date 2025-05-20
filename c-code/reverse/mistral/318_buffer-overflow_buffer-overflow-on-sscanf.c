#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int host_len, port;
    char host[256];

    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%s", host);
    sscanf(argv[2], "%d", &port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) break;

        write(STDOUT_FILENO, buffer, n);

        ssize_t r = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (r > 0) write(sockfd, buffer, r);
    }

    close(sockfd);
    return 0;
}
