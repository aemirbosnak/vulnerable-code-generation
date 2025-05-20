//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MIN_PORT 1
#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *host;
    int start_port, end_port;
    int i;

    if (argc < 2) {
        printf("Usage: %s <host> [start_port] [end_port]\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    if (argc > 2) {
        start_port = atoi(argv[2]);
        if (start_port < MIN_PORT || start_port > MAX_PORT) {
            printf("Invalid starting port specified\n");
            exit(1);
        }
    } else {
        start_port = MIN_PORT;
    }

    if (argc > 3) {
        end_port = atoi(argv[3]);
        if (end_port < MIN_PORT || end_port > MAX_PORT) {
            printf("Invalid ending port specified\n");
            exit(1);
        }
        if (end_port < start_port) {
            printf("Ending port cannot be less than starting port\n");
            exit(1);
        }
    } else {
        end_port = MAX_PORT;
    }

    printf("Scanning ports %d to %d on host %s\n", start_port, end_port, host);

    for (i = start_port; i <= end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Failed to create socket");
            exit(1);
        }

        server.sin_addr.s_addr = inet_addr(host);
        server.sin_family = AF_INET;
        server.sin_port = htons(i);

        // Connect to the server
        int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
        if (result >= 0) {
            printf("Port %d is open\n", i);
        }

        close(sock);
    }

    return 0;
}