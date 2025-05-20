//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT "80"
#define MAX_HOST_LEN 256

struct hostent *gethostbyname(const char *name);

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    char buffer[BUF_SIZE];
    char hostname[MAX_HOST_LEN];
    int port;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Invalid hostname\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    printf("Connecting to %s:%d\n", hostname, port);
    if (connect(sock, host->h_addr, host->h_length) == -1) {
        printf("Error: Could not connect to host\n");
        close(sock);
        return 1;
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sock, buffer, BUF_SIZE, 0) == -1) {
            printf("Error: Could not receive data\n");
            close(sock);
            return 1;
        }
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}