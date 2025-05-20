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

Packet* packets[10];

void simulate_sniffing() {
    for (int i = 0; i < 10; i++) {
        packets[i] = (Packet*)malloc(sizeof(Packet));
        if (packets[i]) {
            packets[i]->size = rand() % MAX_PACKET_SIZE;
            memset(packets[i]->data, 'A' + (i % 26), packets[i]->size);
        }
    }

    // Simulate processing packets
    for (int i = 0; i < 10; i++) {
        printf("Processing packet %d: ", i);
        for (int j = 0; j < packets[i]->size; j++) {
            putchar(packets[i]->data[j]);
        }
        printf("\n");
    }

    // Free some packets
    for (int i = 0; i < 5; i++) {
        free(packets[i]);
        packets[i] = NULL;
    }

    // Use-after-free vulnerability
    for (int i = 5; i < 10; i++) {
        printf("Using freed packet %d: ", i);
        for (int j = 0; j < packets[i]->size; j++) { // Use-after-free
            putchar(packets[i]->data[j]); // Undefined behavior
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    simulate_sniffing();
    return 0;
}
