//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 1024
#define MAX_HOST_LEN 1024
#define MAX_BUF_LEN 4096

int main(int argc, char *argv[]) {
    int sockfd, rc;
    struct sockaddr_in serv_addr;
    struct hostent *host;
    char host_name[MAX_HOST_LEN], buf[MAX_BUF_LEN];
    int port_range[MAX_PORTS];
    int port_start, port_end;
    int i, j;

    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <port-start> <port-end>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(host_name, argv[1], MAX_HOST_LEN);
    port_start = atoi(argv[2]);
    port_end = atoi(argv[3]);

    if (port_start < 1 || port_start > 65535 || port_end < 1 || port_end > 65535 || port_start > port_end) {
        fprintf(stderr, "Invalid port range specified\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(host_name);
    if (!host) {
        fprintf(stderr, "gethostbyname() failed for host '%s'\n", host_name);
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    for (i = port_start; i <= port_end; i++) {
        port_range[i] = 0;
    }

    for (i = port_start; i <= port_end; i++) {
        serv_addr.sin_port = htons(i);

        rc = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (rc == 0) {
            port_range[i] = 1;
            printf("Port %d is open\n", i);
        } else {
            if (errno == ECONNREFUSED) {
                port_range[i] = 0;
                printf("Port %d is closed\n", i);
            } else {
                perror("connect() failed");
                exit(EXIT_FAILURE);
            }
        }

        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket() failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("\nPort scan complete\n");

    for (i = port_start; i <= port_end; i++) {
        if (port_range[i] == 1) {
            printf("Port %d is open\n", i);
        }
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}