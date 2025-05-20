#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    if (sscanf(packet, "%s", buffer) == 1) {
        printf("Received: %s\n", buffer);
    } else {
        printf("Failed to parse packet.\n");
    }
}

int main() {
    char malicious_packet[20] = "ThisIsAVeryLongStringThatWillCauseBufferOverflow";
    process_packet(malicious_packet);
    return 0;
}
