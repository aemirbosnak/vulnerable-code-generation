//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: standalone
// C Port Scanner Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1024

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    char *ip_address;
    int port;
    int i;
    char *ports[MAX_PORTS];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    for (i = 0; i < MAX_PORTS; i++) {
        ports[i] = malloc(sizeof(char) * 5);
        sprintf(ports[i], "%d", i);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_address);
        return 1;
    }

    for (i = 0; i < MAX_PORTS; i++) {
        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
            printf("Port %s is closed\n", ports[i]);
        } else {
            printf("Port %s is open\n", ports[i]);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock < 0) {
                perror("socket");
                return 1;
            }
        }
    }

    close(sock);

    return 0;
}