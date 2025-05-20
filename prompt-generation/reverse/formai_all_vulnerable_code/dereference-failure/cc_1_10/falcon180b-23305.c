//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int sock, ret;
    struct sockaddr_in server_addr;
    int port;
    char buffer[BUFFER_SIZE];
    char *ip;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        if (errno == ECONNREFUSED) {
            printf("%d is closed\n", port);
        } else {
            perror("connect");
        }
        close(sock);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == atoi(argv[2]))
            continue;

        server_addr.sin_port = htons(port);
        ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (ret == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d is closed\n", port);
            } else if (errno == ECONNRESET) {
                printf("%d is filtered\n", port);
            } else {
                perror("connect");
            }
        } else {
            printf("%d is open\n", port);
            close(sock);
            return 0;
        }
    }

    close(sock);
    return 0;
}