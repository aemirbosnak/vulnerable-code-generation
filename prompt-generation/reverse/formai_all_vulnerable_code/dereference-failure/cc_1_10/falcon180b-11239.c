//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE];
    char recv_buf[BUF_SIZE];
    int n;
    fd_set readfds;
    struct timeval tv;

    if (argc < 2) {
        printf("Usage: %s <hostname/IP>\n", argv[0]);
        return 1;
    }

    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(7);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    FD_ZERO(&readfds);
    FD_SET(sock, &readfds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    while (1) {
        if (select(sock + 1, &readfds, NULL, NULL, &tv) < 0) {
            printf("Error: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        if (FD_ISSET(sock, &readfds)) {
            n = recv(sock, recv_buf, BUF_SIZE, 0);
            if (n <= 0) {
                printf("Error: %s\n", strerror(errno));
                close(sock);
                return 1;
            }

            printf("Received: %s", recv_buf);
        }
    }

    close(sock);
    return 0;
}