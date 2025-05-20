//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int ping(char* hostname, int port, int timeout);

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <timeout>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);
    int timeout = atoi(argv[3]);

    int result = ping(hostname, port, timeout);

    if (result == 0) {
        printf("Host is reachable.\n");
    } else {
        printf("Host is not reachable.\n");
    }

    return 0;
}

int ping(char* hostname, int port, int timeout) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    int ret = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        close(sockfd);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received = 0;
    int start_time = time(NULL);

    while (bytes_received < BUFFER_SIZE && time(NULL) - start_time < timeout) {
        int ret = recv(sockfd, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (ret == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            close(sockfd);
            return -1;
        } else if (ret == 0) {
            fprintf(stderr, "Connection closed by server.\n");
            close(sockfd);
            return -1;
        }

        bytes_received += ret;
    }

    close(sockfd);

    if (bytes_received >= BUFFER_SIZE) {
        return 0;
    } else {
        return -1;
    }
}