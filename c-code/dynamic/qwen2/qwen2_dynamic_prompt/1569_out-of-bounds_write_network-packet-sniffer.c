#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(unsigned char *packet, int length) {
    unsigned char buffer[BUFFER_SIZE];
    if (length > BUFFER_SIZE) {
        printf("Packet too large to process\n");
        return;
    }
    memcpy(buffer, packet, length);
    // Intentional out-of-bounds write vulnerability
    buffer[length] = 'A'; // This will overwrite the null terminator of the string
}

int main() {
    unsigned char packet[] = "Example packet data";
    int length = strlen((char *)packet);

    process_packet(packet, length);

    printf("Processed packet: %s\n", packet);

    return 0;
}
