//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in dest_addr;
    struct timeval tv;

    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &dest_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (ret == -1) {
        printf("Error connecting to host\n");
        close(sockfd);
        return -1;
    }

    printf("Connected to host\n");

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));
    if (ret == -1) {
        printf("Error setting receive timeout\n");
        close(sockfd);
        return -1;
    }

    char send_buf[1024];
    strcpy(send_buf, "PING");
    ret = send(sockfd, send_buf, strlen(send_buf), 0);
    if (ret == -1) {
        printf("Error sending data\n");
        close(sockfd);
        return -1;
    }

    char recv_buf[1024] = {0};
    ret = recv(sockfd, recv_buf, sizeof(recv_buf), 0);
    if (ret == -1) {
        printf("Error receiving data\n");
        close(sockfd);
        return -1;
    }

    printf("Received response: %s\n", recv_buf);

    close(sockfd);
    return 0;
}