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

Packet *head = NULL;

void add_packet(const char *data) {
    Packet *new_packet = (Packet *)malloc(sizeof(Packet));
    if (new_packet == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strncpy(new_packet->data, data, BUFFER_SIZE - 1);
    new_packet->data[BUFFER_SIZE - 1] = '\0';
    new_packet->next = head;
    head = new_packet;
}

void process_packets() {
    Packet *current = head;
    while (current != NULL) {
        printf("Processing packet: %s\n", current->data);
        // Simulate processing by freeing the packet immediately
        free(current);
        Packet *temp = current;
        current = current->next;
        temp->next = NULL; // Use after free vulnerability
    }
    head = NULL;
}

int main() {
    add_packet("Packet 1");
    add_packet("Packet 2");
    add_packet("Packet 3");

    process_packets();

    return 0;
}
