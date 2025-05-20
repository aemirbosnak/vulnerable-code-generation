#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <remote_host> <port>\n", argv[0]);
        return 1;
    }

    char remote_host[50];
    int port;

    if (sscanf(argv[1], "%49s", remote_host) != 1 || sscanf(argv[2], "%d", &port) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    // Vulnerability: No bounds checking on remote_host
    printf("Connecting to %s:%d\n", remote_host, port);

    return 0;
}
