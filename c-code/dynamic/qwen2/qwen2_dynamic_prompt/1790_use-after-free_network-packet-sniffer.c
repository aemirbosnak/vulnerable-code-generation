#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct {
    char *data;
    int size;
} Packet;

Packet* create_packet(const char *data, int size) {
    Packet *p = (Packet*)malloc(sizeof(Packet));
    p->data = (char*)malloc(size);
    memcpy(p->data, data, size);
    p->size = size;
    return p;
}

void process_packet(Packet *p) {
    printf("Processing packet: %.*s\n", p->size, p->data);
}

void free_packet(Packet *p) {
    free(p->data);
    free(p);
}

int main() {
    Packet *packet = create_packet("Sample packet data", 20);
    process_packet(packet);

    // Use-after-free vulnerability
    free_packet(packet);
    process_packet(packet); // Use freed memory

    return 0;
}
