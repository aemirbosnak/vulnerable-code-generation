//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_HOST "google.com"
#define PING_PORT 80
#define PING_MAX_RETRY 3

int main() {
    struct sockaddr_in address;
    struct hostent *host;
    int sockfd, n;
    char recv_buf[1024];
    char send_buf[1024];

    if ((host = gethostbyname(PING_HOST)) == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = *(long*)host->h_addr;
    address.sin_port = htons(PING_PORT);

    if (connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("connect");
        exit(1);
    }

    for (n = 0; n < PING_MAX_RETRY; n++) {
        if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (recv(sockfd, recv_buf, sizeof(recv_buf), 0) < 0) {
            perror("recv");
            exit(1);
        }

        printf("Ping #%d: %s\n", n + 1, recv_buf);
    }

    close(sockfd);
    return 0;
}