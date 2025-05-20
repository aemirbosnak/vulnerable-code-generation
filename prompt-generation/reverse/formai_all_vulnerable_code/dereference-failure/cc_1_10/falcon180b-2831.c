//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535
#define PORT_RANGE "1-65535"

void scan(int sock, struct sockaddr_in *serv_addr, int port) {
    if (connect(sock, (struct sockaddr *)serv_addr, sizeof(struct sockaddr)) < 0) {
        if (errno == ECONNREFUSED)
            printf("%d - Closed\n", ntohs(serv_addr->sin_port));
        else if (errno == ETIMEDOUT)
            printf("%d - Filtered\n", ntohs(serv_addr->sin_port));
        else
            printf("%d - Error: %s\n", ntohs(serv_addr->sin_port), strerror(errno));
    } else {
        printf("%d - Open\n", ntohs(serv_addr->sin_port));
        close(sock);
    }
}

int main(int argc, char *argv[]) {
    int sock, port, max_sd;
    struct sockaddr_in serv_addr;
    char hostname[256];
    char *target_ip;
    char *port_range;

    if (argc!= 3) {
        printf("Usage:./port_scanner <target_ip> <port_range>\n");
        exit(1);
    }

    target_ip = argv[1];
    port_range = argv[2];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port_range));

    if (inet_pton(AF_INET, target_ip, &serv_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    for (port = 1; port <= MAX; port++) {
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("%s:%d - Open\n", target_ip, port);
            close(sock);
        } else {
            if (errno == ECONNREFUSED)
                printf("%s:%d - Closed\n", target_ip, port);
            else if (errno == ETIMEDOUT)
                printf("%s:%d - Filtered\n", target_ip, port);
            else
                printf("%s:%d - Error: %s\n", target_ip, port, strerror(errno));
        }
    }

    close(sock);

    return 0;
}