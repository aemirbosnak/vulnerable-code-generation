//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PING_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct hostent *he;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Error: cannot resolve host %s\n", host);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(he->h_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: cannot create socket\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error: cannot connect to %s\n", host);
        return 1;
    }

    char *ping_data = "PING";
    int ping_data_len = strlen(ping_data);
    int n = write(sock, ping_data, ping_data_len);
    if (n < 0) {
        printf("Error: cannot write to socket\n");
        return 1;
    }

    char buf[PING_BUF_SIZE];
    memset(buf, 0, PING_BUF_SIZE);
    n = read(sock, buf, PING_BUF_SIZE);
    if (n < 0) {
        printf("Error: cannot read from socket\n");
        return 1;
    }

    printf("Received %d bytes from %s\n", n, host);
    printf("Data: %s\n", buf);

    close(sock);

    return 0;
}