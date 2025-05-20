#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode(char *data) {
    char buffer[BUFFER_SIZE];
    char *packet = malloc(BUFFER_SIZE);
    int offset = 0;

    printf("Streaming audio data...\n");

    while (1) {
        printf("Enter audio packet (or 'q' to quit): ");
        gets(buffer);

        strcpy(packet, buffer);

        // Simulate packet parsing
        int i;
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (packet[i] == '\0') break;
            offset++;

            // Buffer overflow - write past the end of 'data' buffer
            data[offset] = packet[i];
        }

        if (strchr(buffer, 'q')) break;
    }

    free(packet);
    printf("Exiting...\n");
}

int main() {
    char data[BUFFER_SIZE];
    memset(data, 0, BUFFER_SIZE);

    decode(data);

    return 0;
}
