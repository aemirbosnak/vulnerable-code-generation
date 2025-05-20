//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 80
#define IP "192.168.0.1"
#define TIMEOUT 10

int main(int argc, char *argv[]) {
    struct sockaddr_in addr;
    struct hostent *host;
    int sock, n;
    char buf[BUF_SIZE];
    struct timeval tv;

    if ((host = gethostbyname(IP)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = *(long*)host->h_addr_list[0];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    n = write(sock, "Hello, world!", strlen("Hello, world!") + 1);
    if (n < 0) {
        perror("write");
        exit(1);
    }

    n = read(sock, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }

    printf("Received %d bytes: %s\n", n, buf);

    close(sock);

    return 0;
}