#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Packet {
    char data[BUFFER_SIZE];
    struct Packet *next;
} Packet;

Packet *packet_list = NULL;

void add_packet(const char *data) {
    Packet *new_packet = (Packet *)malloc(sizeof(Packet));
    if (new_packet == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(new_packet->data, data, BUFFER_SIZE - 1);
    new_packet->data[BUFFER_SIZE - 1] = '\0';
    new_packet->next = packet_list;
    packet_list = new_packet;
}

void process_packets() {
    Packet *current = packet_list;
    while (current != NULL) {
        printf("Processing packet: %s\n", current->data);
        // Simulate processing time
        sleep(1);
        Packet *temp = current;
        current = current->next;
        free(temp); // Freeing the memory
    }
    packet_list = NULL; // Resetting the list pointer
}

int main() {
    add_packet("Packet 1");
    add_packet("Packet 2");
    add_packet("Packet 3");

    process_packets();

    // Use after free vulnerability
    printf("Use after free: %s\n", packet_list->data);

    return 0;
}
