//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MAX 65535
#define BUF_SIZE 1024

void print_help(char *prog_name) {
    fprintf(stdout, "Usage: %s <host> <port>\n", prog_name);
    fprintf(stdout, "  <host> - target host IP address or hostname\n");
    fprintf(stdout, "  <port> - target port number\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_help(argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    if (port < 1 || port > PORT_MAX) {
        fprintf(stderr, "Error: Invalid port number\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        fprintf(stderr, "Error: Socket creation failed\n");
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        fprintf(stderr, "Error: setsockopt() failed\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(host);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out on port %d\n", port);
        } else if (errno == EHOSTUNREACH) {
            printf("Host is unreachable on port %d\n", port);
        } else {
            fprintf(stderr, "Error: Connection failed on port %d\n", port);
        }

        close(sockfd);
        return 1;
    }

    printf("Port %d is open\n", port);

    close(sockfd);
    return 0;
}