//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);
    hostname[MAX_HOSTNAME_LEN - 1] = '\0';

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sock);
        return 1;
    }

    char data[MAX_DATA_LEN];
    snprintf(data, MAX_DATA_LEN, "PING %s\r\n", hostname);

    if (send(sock, data, strlen(data), 0) == -1) {
        perror("send");
        close(sock);
        return 1;
    }

    char buffer[MAX_DATA_LEN];
    memset(buffer, 0, sizeof(buffer));

    int bytes_received = 0;
    while (bytes_received < MAX_DATA_LEN) {
        int result = recv(sock, buffer + bytes_received, MAX_DATA_LEN - bytes_received, 0);
        if (result <= 0) {
            if (result == 0) {
                fprintf(stderr, "Connection closed by remote host\n");
            } else {
                perror("recv");
            }
            close(sock);
            return 1;
        }

        bytes_received += result;
    }

    close(sock);

    if (strstr(buffer, "PING")) {
        fprintf(stdout, "Host is reachable\n");
    } else {
        fprintf(stdout, "Host is unreachable\n");
    }

    return 0;
}