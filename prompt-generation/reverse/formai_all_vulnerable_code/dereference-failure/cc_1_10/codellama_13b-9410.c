//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Romeo and Juliet
/*
 * Romeo and Juliet Port Scanner
 *
 * Scans a given IP address for open ports and prints the results.
 *
 * Usage: ./port_scanner <ip_address>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535
#define IP_ADDRESS_LEN 20

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./port_scanner <ip_address>\n");
        return 1;
    }

    char ip_address[IP_ADDRESS_LEN];
    strcpy(ip_address, argv[1]);

    struct addrinfo hints;
    struct addrinfo *server_info, *p;
    int status, sockfd, port;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((status = getaddrinfo(ip_address, NULL, &hints, &server_info)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = server_info; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        for (port = PORT_RANGE_START; port <= PORT_RANGE_END; port++) {
            if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
                close(sockfd);
                continue;
            }

            printf("Port %d is open\n", port);
            close(sockfd);
        }
    }

    freeaddrinfo(server_info);
    return 0;
}