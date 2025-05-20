//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 64
#define MAX_DATA_LEN 64
#define TRUE 1
#define FALSE 0
#define PORT 7


int main(int argc, char *argv[]) {
    int sock, ret;
    struct hostent *host;
    struct sockaddr_in addr;
    char hostname[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    if ((host = gethostbyname(hostname)) == NULL) {
        printf("Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    if (host->h_addrtype!= AF_INET) {
        printf("Error: Invalid address type\n");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (send(sock, data, strlen(data), 0) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (recv(sock, data, MAX_DATA_LEN, 0) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received: %s\n", data);

    close(sock);
    exit(0);
}