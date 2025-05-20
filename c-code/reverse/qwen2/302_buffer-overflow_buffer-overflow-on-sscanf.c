#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char response[10];
    int port;

    // Simulate receiving an overly long PASV response
    strcpy(response, "227 Entering Passive Mode (192.168.1.1,65535,65535)");

    // Vulnerable sscanf call
    if (sscanf(response, "227 Entering Passive Mode (%*[^,],%d,%d)", &port) != 2) {
        fprintf(stderr, "Failed to parse response\n");
        return 1;
    }

    printf("Port: %d\n", port);

    return 0;
}
