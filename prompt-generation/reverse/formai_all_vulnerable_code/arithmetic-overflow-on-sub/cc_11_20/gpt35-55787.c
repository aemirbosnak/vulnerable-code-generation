//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int main(int argc, char *argv[]) {
    int opt, start_port, end_port;
    char *target;
    struct hostent *host;
    struct sockaddr_in target_addr;
    printf("\n[+] CyberPunk Port Scanner [+]\n\n");

    if (argc < 2) {
        printf("Usage: %s <target> [start-port] [end-port]\n", argv[0]);
        exit(1);
    }

    target = argv[1];

    if ((host = gethostbyname(target)) == NULL) {
        printf("Error: Cannot resolve target\n");
        exit(1);
    }

    memcpy(&target_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    target_addr.sin_family = AF_INET;

    printf("[*] Scanning target %s\n\n", target);

    start_port = PORT_MIN;
    end_port = PORT_MAX;

    if (argc > 2) {
        start_port = strtol(argv[2], (char **) NULL, 10);
        if (start_port < PORT_MIN || start_port > PORT_MAX) {
            printf("Error: Invalid start port\n");
            exit(1);
        }
        if (argc > 3) {
            end_port = strtol(argv[3], (char **) NULL, 10);
            if (end_port < PORT_MIN || end_port > PORT_MAX) {
                printf("Error: Invalid end port\n");
                exit(1);
            }
        }
    }

    for (int port = start_port; port <= end_port; port++) {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            printf("Error: Cannot create socket\n");
            exit(1);
        }

        target_addr.sin_port = htons(port);
        if (connect(socket_fd, (struct sockaddr *) &target_addr, sizeof(target_addr)) < 0) {
            close(socket_fd);
            continue;
        }

        printf("[+] Port %d is open\n", port);
        close(socket_fd);
    }
    printf("\n[+] Port scan complete\n");
    return 0;
}