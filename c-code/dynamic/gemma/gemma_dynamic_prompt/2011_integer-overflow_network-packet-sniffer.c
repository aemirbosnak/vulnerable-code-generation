#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int packet_size = 1000000000; // 1GB packet size
    int buffer_size = packet_size + 1;
    char *buffer = malloc(buffer_size);

    // Deliberate integer overflow
    int overflow_value = packet_size * 2;
    int result = overflow_value + 1; // Overflow!

    if (result < 0) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // Sniffing code...

    free(buffer);
    return 0;
}
