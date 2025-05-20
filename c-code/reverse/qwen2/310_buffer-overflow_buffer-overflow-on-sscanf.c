#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <remote_host> <port>\n", argv[0]);
        return 1;
    }

    char remote_host[256];
    int port;

    if (sscanf(argv[1], "%255s", remote_host) != 1 || sscanf(argv[2], "%d", &port) != 1) {
        fprintf(stderr, "Invalid input format\n");
        return 1;
    }

    printf("Connecting to %s:%d\n", remote_host, port);

    // Simulate connection setup
    sleep(2);

    printf("Connection established\n");

    return 0;
}
