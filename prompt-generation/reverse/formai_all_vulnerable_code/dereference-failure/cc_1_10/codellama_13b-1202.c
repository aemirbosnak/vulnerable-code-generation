//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char send_buf[1024], recv_buf[1024];
    struct sockaddr_in serv_addr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <ip> <port_range_start> <port_range_end>\n", argv[0]);
        exit(1);
    }

    memset(send_buf, 0, sizeof(send_buf));
    memset(recv_buf, 0, sizeof(recv_buf));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    for (int port = atoi(argv[2]); port <= atoi(argv[3]); port++) {
        serv_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
            printf("Port %d: closed\n", port);
        } else {
            printf("Port %d: open\n", port);
            close(sockfd);
        }
    }

    close(sockfd);

    return 0;
}