//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PING_COUNT 10
#define PING_INTERVAL 1000

int main(int argc, char *argv[]) {
    int sockfd, n, ping_count;
    char recv_buf[1024];
    struct sockaddr_in server_addr;
    struct hostent *server;
    char *host = argv[1];
    char *port = argv[2];

    if ((server = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Pinging %s on port %s\n", host, port);

    for (ping_count = 1; ping_count <= PING_COUNT; ping_count++) {
        printf("Ping #%d: ", ping_count);
        fflush(stdout);
        if (send(sockfd, "PING", 4, 0) == -1) {
            perror("send");
            exit(1);
        }
        if ((n = recv(sockfd, recv_buf, 1024, 0)) == -1) {
            perror("recv");
            exit(1);
        }
        printf("%d bytes from %s: PING\n", n, host);
        sleep(PING_INTERVAL);
    }

    close(sockfd);
    return 0;
}