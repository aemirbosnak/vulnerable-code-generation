//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TRUE 1
#define FALSE 0
#define PORT 7

void die(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    int sock;
    struct hostent* host;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        die("socket");
    }

    host = gethostbyname(hostname);

    if (host == NULL) {
        die("gethostbyname");
    }

    memset(&data, 0, MAX_DATA);

    sprintf(data, "PING %s\r\n", hostname);

    if (send(sock, data, strlen(data), 0) == -1) {
        die("send");
    }

    while (TRUE) {
        char buffer[MAX_DATA];
        int bytes_received;

        bytes_received = recv(sock, buffer, MAX_DATA, 0);

        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}