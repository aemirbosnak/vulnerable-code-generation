#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    int length;
} Packet;

Packet* create_packet(const char *data, int length) {
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
        printf("Error: Null pointer encountered.\n");
    }
}

int main() {
    const char *sample_data = "Sample packet data";
    Packet *packet = create_packet(sample_data, strlen(sample_data));

    if (packet == NULL) {
        printf("Failed to create packet.\n");
        return EXIT_FAILURE;
    }

    process_packet(packet);

    // Intentionally causing a null pointer dereference
    Packet *null_packet = NULL;
    process_packet(null_packet); // This will cause a dereference failure

    free(packet->data);
    free(packet);

    return EXIT_SUCCESS;
}
