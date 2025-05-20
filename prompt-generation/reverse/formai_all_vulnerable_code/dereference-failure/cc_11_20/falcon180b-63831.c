//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    int sock, ret;
    struct addrinfo hints, *res;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    char *ptr;
    int port;
    int i;
    int status = 0;
    int interval = 1;
    int timeout = 5;
    int num_pings = 0;

    // Get hostname
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    // Get IP address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    if ((ret = getaddrinfo(host, service, &hints, &res))!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    // Create socket
    sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    if (connect(sock, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Pinging %s:%d...\n", host, port);
    for (i = 0; i < interval; i++) {
        if (send(sock, "PING", strlen("PING"), 0) == -1) {
            perror("send");
            exit(1);
        }
        status = 0;
        while (status == 0) {
            if (recv(sock, service, NI_MAXSERV, 0) == -1) {
                perror("recv");
                exit(1);
            }
            if (strstr(service, "PONG")!= NULL) {
                status = 1;
            }
        }
        if (status == 1) {
            num_pings++;
        } else {
            printf("No response from server\n");
        }
        usleep(timeout * 1000);
    }

    printf("Ping test completed: %d pings sent, %d pings received\n", interval, num_pings);

    close(sock);
    freeaddrinfo(res);
    return 0;
}