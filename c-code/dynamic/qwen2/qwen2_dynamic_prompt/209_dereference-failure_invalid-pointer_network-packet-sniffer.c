#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char *data;
    size_t length;
} Packet;

Packet* create_packet(const char *data, size_t length) {
    Packet *packet = (Packet *)malloc(sizeof(Packet));
    if (packet == NULL) {
        return NULL;
    }
    packet->data = (unsigned char *)malloc(length);
    if (packet->data == NULL) {
        free(packet);
        return NULL;
    }
    memcpy(packet->data, data, length);
    packet->length = length;
    return packet;
}

void process_packet(Packet *packet) {
    if (packet == NULL || packet->data == NULL) {
        printf("Invalid packet\n");
        return;
    }
    // Deliberate dereference failure: accessing invalid memory
    unsigned char value = *(packet->data + packet->length); // Out-of-bounds access
    printf("Value: %d\n", value);
}

int main() {
    const char *data = "Sample packet data";
    Packet *packet = create_packet(data, strlen(data));
    if (packet != NULL) {
        process_packet(packet);
        free(packet->data);
        free(packet);
    } else {
        printf("Failed to create packet\n");
    }
    return 0;
}
