//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

typedef struct {
    char *ip;
    int port;
} Target;

int ping(Target target) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA_SIZE] = "PING";
    char recv_data[MAX_DATA_SIZE];
    struct timeval timeout = {TIMEOUT, 0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, target.ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(target.port);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in));
    if (ret == -1) {
        close(sockfd);
        printf("Connection failed\n");
        exit(EXIT_FAILURE);
    }

    ret = send(sockfd, send_data, strlen(send_data), 0);
    if (ret == -1) {
        close(sockfd);
        printf("Send failed\n");
        exit(EXIT_FAILURE);
    }

    memset(recv_data, 0, sizeof(recv_data));
    ret = recv(sockfd, recv_data, sizeof(recv_data), 0);
    if (ret <= 0) {
        close(sockfd);
        printf("Recv failed\n");
        exit(EXIT_FAILURE);
    }

    close(sockfd);

    if (strcmp(recv_data, "PONG") == 0) {
        printf("Target is alive\n");
        return 0;
    } else {
        printf("Target is not alive\n");
        return 1;
    }
}

int main(int argc, char **argv) {
    Target target;

    if (argc!= 4) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    target.ip = argv[1];
    target.port = atoi(argv[2]);

    ping(target);

    return 0;
}