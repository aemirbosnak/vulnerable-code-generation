#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parsePASVResponse(char *response) {
    int port[6];
    if (sscanf(response, "227 Entering Passive Mode (%d,%d,%d,%d,%d,%d)", &port[0], &port[1], &port[2], &port[3], &port[4], &port[5]) != 6) {
        return;
    }
    // Vulnerability: Buffer overflow due to fixed-size array
    char buffer[10];
    sprintf(buffer, "%d%d%d%d%d%d", port[0], port[1], port[2], port[3], port[4], port[5]);
}

int main() {
    char response[] = "227 Entering Passive Mode (192,168,1,1,123,45)";
    parsePASVResponse(response);
    return 0;
}
