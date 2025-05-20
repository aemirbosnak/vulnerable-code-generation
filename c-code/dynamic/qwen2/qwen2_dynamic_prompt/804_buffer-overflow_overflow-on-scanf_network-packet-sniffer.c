#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void process_packet(char *packet) {
    char buffer[BUFFER_SIZE];
    printf("Received packet: %s\n", packet);
    // Vulnerability: No bounds checking on scanf
    scanf("%s", buffer); // This will cause a buffer overflow if input is longer than BUFFER_SIZE
}

int main() {
    char packet[200];
    printf("Enter a packet to sniff:\n");
    fgets(packet, sizeof(packet), stdin);
    process_packet(packet);
    return 0;
}
