#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Packet {
    char data[BUFFER_SIZE];
} Packet;

Packet* capture_packet() {
    Packet* packet = (Packet*)malloc(sizeof(Packet));
    if (packet == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(packet->data, "Sample packet data");
    return packet;
}

void process_packet(Packet* packet) {
    printf("Processing packet: %s\n", packet->data);
}

int main() {
    Packet* packet = capture_packet();
    process_packet(packet);

    // Use after free vulnerability
    free(packet);
    process_packet(packet); // Use after free

    return 0;
}
