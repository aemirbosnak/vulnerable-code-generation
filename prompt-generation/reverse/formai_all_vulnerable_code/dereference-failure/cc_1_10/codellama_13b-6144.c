//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_URL_LEN 256
#define MAX_BUFFER_LEN 4096

void print_usage(const char *program_name) {
    printf("Usage: %s <URL>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    char url[MAX_URL_LEN];
    char buffer[MAX_BUFFER_LEN];
    int socket_fd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc != 2) {
        print_usage(argv[0]);
    }

    strncpy(url, argv[1], MAX_URL_LEN - 1);

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname(url);
    if (server == NULL) {
        fprintf(stderr, "Error: unable to resolve hostname\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    n = write(socket_fd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }

    while ((n = read(socket_fd, buffer, MAX_BUFFER_LEN)) > 0) {
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("read failed");
        exit(1);
    }

    return 0;
}