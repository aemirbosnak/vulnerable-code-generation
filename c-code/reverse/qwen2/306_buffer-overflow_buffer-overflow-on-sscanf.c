#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parsePASVResponse(char *response) {
    int ports[6];
    if (sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &ports[0], &ports[1], &ports[2], &ports[3], &ports[4], &ports[5]) != 6) {
        printf("Failed to parse PASV response\n");
        return;
    }
    int port = (ports[4] << 8) | ports[5];
    printf("Connected to port: %d\n", port);
}

int main() {
    char response[1024];
    fgets(response, sizeof(response), stdin);
    parsePASVResponse(response);
    return 0;
}
