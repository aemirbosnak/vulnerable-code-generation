//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: optimized
// Optimized C Network Ping Test example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_IP_LEN 16

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strcpy(hostname, argv[1]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname: %s\n", hstrerror(h_errno));
        return 1;
    }

    char ip[MAX_IP_LEN];
    strcpy(ip, inet_ntoa(*(struct in_addr *)host->h_addr));

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: Unable to create socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(ip);

    int connect_result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (connect_result < 0) {
        fprintf(stderr, "Error: Unable to connect to host: %s\n", strerror(errno));
        return 1;
    }

    char buffer[1024];
    int n = recv(sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        fprintf(stderr, "Error: Unable to receive data from host: %s\n", strerror(errno));
        return 1;
    }

    printf("Ping successful! Received %d bytes from %s\n", n, ip);

    close(sock);
    return 0;
}