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

#define MAX_PACKET_SIZE 1024
#define BUFFER_SIZE 256

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        die("ERROR on binding");

    listen(sockfd, 1);
    clilen = sizeof(cli_addr);

    printf("Listening on port %s...\n", argv[1]);

    while (1) {
        new_fd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (new_fd < 0) die("ERROR on accept");

        memset(buffer, 0, BUFFER_SIZE);
        gets(buffer);
    }

    return 0;
}
