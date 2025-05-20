//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 5

// Function to print error message and exit program
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to send ICMP echo request and receive response
int ping(char *host, int count, int interval) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        error("socket() failed");
    }

    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(host);

    char buffer[BUFFER_SIZE];
    int length = strlen(host) + 1;

    for (int i = 0; i < count; i++) {
        sendto(sock, host, length, 0, (struct sockaddr *)&target, sizeof(target));
        int timeout = interval * 1000;
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);
        select(sock + 1, &readfds, NULL, NULL, &timeout);

        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Timeout\n");
            continue;
        }

        if (buffer[0] == '!' && buffer[1] == '!' && buffer[2] == '!' && buffer[3] == '!') {
            printf("Reply from %s: bytes=%d time=%dms TTL=%d\n", host, bytes_received, (int)(interval * 1000), buffer[4] << 8 | buffer[5]);
        } else {
            printf("Reply from %s: bytes=%d time=%dms TTL=%d\n", host, bytes_received, (int)(interval * 1000), 0);
        }
    }

    close(sock);
    return 0;
}

// Function to resolve hostname to IP address
int resolve_host(char *host, struct in_addr *ip) {
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        error("gethostbyname() failed");
    }

    memcpy(ip, he->h_addr, he->h_length);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s host count interval\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int count = atoi(argv[2]);
    int interval = atoi(argv[3]);

    struct in_addr ip;
    resolve_host(host, &ip);

    printf("PING %s (%s) %d(s) %d bytes of data.\n", host, inet_ntoa(ip), interval, count);
    ping(host, count, interval);

    return 0;
}