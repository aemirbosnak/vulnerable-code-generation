//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORTS 1024

void scan_ports(const char* host, int min_port, int max_port) {
    struct sockaddr_in server;
    struct hostent* hp;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    hp = gethostbyname(host);
    if (hp == NULL) {
        fprintf(stderr, "unknown host: %s\n", host);
        exit(1);
    }

    bzero((char*) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy(hp->h_addr, (char*) &server.sin_addr, hp->h_length);

    for (int i = min_port; i <= max_port; i++) {
        server.sin_port = htons(i);
        if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
            continue;
        }
        printf("port %d is open\n", i);
        close(sock);
        return;
    }

    printf("no open ports found\n");
    close(sock);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s host min_port max_port\n", argv[0]);
        exit(1);
    }

    scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}