//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

// Function to print error message and exit program
void error(const char *message) {
    perror(message);
    exit(1);
}

// Function to send a ping request and receive a response
int ping(const char *hostname) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        error("gethostbyname");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        error("connect");
    }

    char buf[BUF_SIZE];
    send(sock, "PING\n", 6, 0);

    int bytes_received = recv(sock, buf, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        error("recv");
    }

    buf[bytes_received] = '\0';
    printf("Response: %s\n", buf);

    close(sock);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    ping(argv[1]);

    return 0;
}