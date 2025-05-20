//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define TIMEOUT 5

int port_scan(char *hostname, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    port_scan(hostname, start_port, end_port);

    return 0;
}

int port_scan(char *hostname, int start_port, int end_port) {
    int sock, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("No such host: %s\n", hostname);
        return 1;
    }

    for (port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket failed");
            exit(1);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr = *((struct in_addr *) server->h_addr);

        if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else if (errno == ETIMEDOUT) {
                printf("Port %d is filtered\n", port);
            } else {
                printf("Error on port %d\n", port);
            }
        }

        close(sock);
    }

    return 0;
}