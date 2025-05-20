#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 10

void process_packet(const char *packet) {
    char destination[BUFFER_SIZE];
    if (sscanf(packet, "packet to %s", destination) != 1) {
        fprintf(stderr, "Invalid packet format\n");
        return;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <packet>\n", argv[0]);
        return 1;
    }

    process_packet(argv[1]);

    return 0;
}
