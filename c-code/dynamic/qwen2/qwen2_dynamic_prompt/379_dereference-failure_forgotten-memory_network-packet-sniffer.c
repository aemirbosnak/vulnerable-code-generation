#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} Packet;

Packet* create_packet(const char *data, size_t length) {
    Packet *packet = (Packet *)malloc(sizeof(Packet));
    if (packet == NULL) {
        return NULL;
    }
    packet->data = (char *)malloc(length + 1);
    if (packet->data == NULL) {
        free(packet);
        return NULL;
    }
    strncpy(packet->data, data, length);
    packet->data[length] = '\0';
    packet->length = length;
    return packet;
}

void process_packet(Packet *packet) {
    if (packet != NULL && packet->data != NULL) {
        printf("Processing packet: %s\n", packet->data);
    } else {
        printf("Invalid packet\n");
    }
}

int main() {
    const char *sample_data = "Sample packet data";
    Packet *packet = create_packet(sample_data, strlen(sample_data));

    if (packet != NULL) {
        process_packet(packet);
        // Deliberate dereference failure by forgetting to free the packet
        // This will cause a memory leak
    }

    // Intentionally not freeing the packet here

    return 0;
}
