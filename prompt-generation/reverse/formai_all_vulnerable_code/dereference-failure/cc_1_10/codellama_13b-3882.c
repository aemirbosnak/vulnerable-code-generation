//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_START 1024
#define PORT_END 65535

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct hostent *hostinfo;

    if ((hostinfo = gethostbyname(host)) == NULL) {
        printf("Host %s not found\n", host);
        return 1;
    }

    char *ip = inet_ntoa(*((struct in_addr *) hostinfo->h_addr_list[0]));

    for (int port = PORT_START; port <= PORT_END; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Failed to create socket\n");
            return 1;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip);

        if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            close(sock);
        }
    }

    return 0;
}