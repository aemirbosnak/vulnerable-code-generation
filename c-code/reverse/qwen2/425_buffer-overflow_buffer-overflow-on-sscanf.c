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
    int dataPort = (ports[4] << 8) | ports[5];
    char buffer[dataPort]; // Vulnerable: Fixed-size buffer
    memset(buffer, 'A', sizeof(buffer));
}

int main() {
    char response[] = "227 Entering Passive Mode (192,168,1,1,123,45)";
    parsePASVResponse(response);
    return 0;
}
