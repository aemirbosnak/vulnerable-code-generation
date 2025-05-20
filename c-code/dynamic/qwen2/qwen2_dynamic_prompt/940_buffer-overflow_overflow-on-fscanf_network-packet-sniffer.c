#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    printf("Processing packet...\n");
    fscanf(packet, "%s", buffer); // Vulnerable to buffer overflow
}

int main() {
    char malicious_packet[20] = "ThisIsAVeryLongPacketThatWillCauseBufferOverflow";
    process_packet(malicious_packet);
    return 0;
}
