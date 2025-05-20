//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

void die(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char recv_buf[MAX_DATA_SIZE];
    char send_buf[MAX_DATA_SIZE];
    int addrlen = sizeof(server_addr);

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket() failed");
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, addrlen);
    if (ret == -1) {
        if (errno == ECONNREFUSED) {
            printf("Server is not running on %s:%d\n", argv[1], atoi(argv[2]));
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            die("connect() failed");
        }
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    strcpy(send_buf, "PING");
    ret = send(sock, send_buf, strlen(send_buf), 0);
    if (ret == -1) {
        die("send() failed");
    }

    memset(recv_buf, 0, MAX_DATA_SIZE);
    ret = recv(sock, recv_buf, MAX_DATA_SIZE, 0);
    if (ret == -1) {
        die("recv() failed");
    }

    printf("Received response: %s\n", recv_buf);

    close(sock);
    return 0;
}