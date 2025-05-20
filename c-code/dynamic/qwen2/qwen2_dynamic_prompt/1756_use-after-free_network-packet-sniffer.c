#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024

typedef struct {
    char data[MAX_PACKET_SIZE];
    int size;
} Packet;

Packet* create_packet(const char* data, int size) {
    Packet* p = (Packet*)malloc(sizeof(Packet));
    if (p == NULL) return NULL;
    memcpy(p->data, data, size);
    p->size = size;
    return p;
}

void process_packet(Packet* p) {
    // Simulate processing by printing the first byte
    printf("Processing packet: %d\n", p->data[0]);
}

void free_packet(Packet* p) {
    free(p);
}

int main() {
    Packet* packets[10];
    for (int i = 0; i < 10; i++) {
        packets[i] = create_packet("Hello", 5);
    }

    for (int i = 0; i < 10; i++) {
        process_packet(packets[i]);
        free_packet(packets[i]);
    }

    // Use-after-free vulnerability
    process_packet(packets[5]);

    return 0;
}
