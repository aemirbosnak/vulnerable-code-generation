#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <remote_host:port>\n", argv[0]);
        return 1;
    }

    int listen_port;
    char remote_host[256];
    char remote_port[6];

    sscanf(argv[2], "%[^:]:%s", remote_host, remote_port);
    listen_port = atoi(argv[1]);

    printf("Listening on port: %d\n", listen_port);
    printf("Remote host: %s\n", remote_host);
    printf("Remote port: %s\n", remote_port);

    return 0;
}
