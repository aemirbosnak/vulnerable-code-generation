//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_ADDRESS_LEN 16

void print_ip_address(struct in_addr address) {
    char ip_address[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &address, ip_address, INET_ADDRSTRLEN);
    printf("IP Address: %s\n", ip_address);
}

int main(int argc, char **argv) {
    struct addrinfo hints;
    struct addrinfo *server_info, *p;
    int sock, ret;
    char hostname[MAX_HOSTNAME_LEN];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(argv[1], NULL, &hints, &server_info);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    for (p = server_info; p != NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", argv[1]);
        return 1;
    }

    printf("Connected to %s\n", argv[1]);

    gethostname(hostname, MAX_HOSTNAME_LEN);
    printf("Hostname: %s\n", hostname);

    print_ip_address(((struct sockaddr_in *)p->ai_addr)->sin_addr);

    close(sock);

    return 0;
}