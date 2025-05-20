#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void parse_response(char *response) {
    char ip[16];
    int port;
    if (sscanf(response, "227 Entering Passive Mode (%[^,],%d,%d)", ip, &port, &port) != 3) {
        printf("Failed to parse response\n");
        return;
    }
    // Intentional buffer overflow vulnerability
    char large_buffer[BUFFER_SIZE];
    snprintf(large_buffer, sizeof(large_buffer), "%s:%d", ip, port);
}

int main() {
    char response[BUFFER_SIZE] = "227 Entering Passive Mode (192.168.1.1,123,45)";
    parse_response(response);
    return 0;
}
