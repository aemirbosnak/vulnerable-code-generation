//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_DATA_LENGTH 1024

int main(int argc, char *argv[]) {
    int sock, ret;
    struct hostent *host;
    char hostname[MAX_HOSTNAME_LENGTH];
    char data[MAX_DATA_LENGTH];
    int datalen;

    if (argc!= 3) {
        printf("Usage: %s host data\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME_LENGTH);
    datalen = strlen(argv[2]);

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    if (host->h_addrtype!= AF_INET) {
        printf("Error: Invalid address type\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    ret = connect(sock, (struct sockaddr *)host->h_addr, host->h_length);
    if (ret == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    ret = send(sock, argv[2], datalen, 0);
    if (ret == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    ret = recv(sock, data, MAX_DATA_LENGTH, 0);
    if (ret == -1) {
        printf("Error: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    data[ret] = '\0';
    printf("Received data: %s\n", data);

    close(sock);
    return 0;
}