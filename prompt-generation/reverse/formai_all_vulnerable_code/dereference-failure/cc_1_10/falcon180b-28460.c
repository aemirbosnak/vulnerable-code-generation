//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct hostent *host;
    char *hostname;
    char buffer[BUF_SIZE];
    int bytes_received;
    struct sockaddr_in server_addr;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: %s not found.\n", hostname);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error: socket() failed.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: connect() failed.\n");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        bytes_received = recv(sock, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error: recv() failed.\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}