//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define MAX_TRIES 5
#define TIMEOUT 5000

int ping(const char *hostname) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char recv_buf[BUF_SIZE];
    int recv_buf_len = BUF_SIZE;
    int num_tries = 0;
    struct timeval timeout;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    server_addr.sin_port = htons(7);

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down\n");
        } else {
            perror("connect");
        }
        close(sockfd);
        return -1;
    }

    printf("Host is up\n");
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int retval;

    for (int i = 0; i < MAX_TRIES; i++) {
        retval = ping(hostname);
        if (retval == 0) {
            printf("Ping successful after %d tries\n", i + 1);
            return 0;
        } else if (retval == -1) {
            printf("Ping failed after %d tries\n", i + 1);
            return 1;
        }
    }

    printf("Ping timed out after %d tries\n", MAX_TRIES);
    return 1;
}