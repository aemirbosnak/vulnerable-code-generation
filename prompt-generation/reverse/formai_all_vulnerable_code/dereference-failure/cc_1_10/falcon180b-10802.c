//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024

void die(const char *str) {
    perror(str);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("connect");
    }

    char send_data[MAX_DATA_SIZE];
    memset(send_data, 'A', MAX_DATA_SIZE);

    if (send(sockfd, send_data, MAX_DATA_SIZE, 0) == -1) {
        die("send");
    }

    char recv_data[MAX_DATA_SIZE];
    memset(recv_data, 0, MAX_DATA_SIZE);

    int recv_size = recv(sockfd, recv_data, MAX_DATA_SIZE, 0);
    if (recv_size <= 0) {
        die("recv");
    }

    printf("Received data: %s\n", recv_data);

    close(sockfd);
    return 0;
}