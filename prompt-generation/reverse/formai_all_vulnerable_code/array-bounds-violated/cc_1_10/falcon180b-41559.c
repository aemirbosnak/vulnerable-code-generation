//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <hostname>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        usage(argv[0]);
        return 1;
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Connection refused\n");
        } else {
            die("connect");
        }
    }

    char buf[BUF_SIZE];
    ssize_t bytes_received;
    while ((bytes_received = recv(sock, buf, BUF_SIZE, 0)) > 0) {
        buf[bytes_received] = '\0';
        printf("%s", buf);
        fflush(stdout);
    }

    if (bytes_received == -1) {
        die("recv");
    }

    close(sock);
    return 0;
}