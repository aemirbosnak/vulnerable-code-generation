//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
// internet_speed_test.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define TIMEOUT 5

void print_usage(char *program_name) {
    fprintf(stderr, "Usage: %s <url>\n", program_name);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        print_usage(argv[0]);
    }

    char *url = argv[1];
    char *host = strtok(url, ":");
    char *port = strtok(NULL, ":");

    struct addrinfo hints;
    struct addrinfo *server_info;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(host, port, &hints, &server_info) != 0) {
        perror("getaddrinfo failed");
        exit(1);
    }

    int sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) < 0) {
        perror("connect failed");
        exit(1);
    }

    freeaddrinfo(server_info);

    char buffer[BUFFER_SIZE];
    int n;
    struct timeval start, end;
    double elapsed_time;

    gettimeofday(&start, NULL);

    n = send(sock, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("send failed");
        exit(1);
    }

    n = recv(sock, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv failed");
        exit(1);
    }

    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Download Speed: %.2f KB/s\n", (n * 8.0) / (1024.0 * elapsed_time));

    close(sock);

    return 0;
}