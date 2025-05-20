#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int id;
    char* data;
} AudioPacket;

void decodeAudio(AudioPacket* packet) {
    // Simulate decoding by printing the data
    printf("Decoding audio packet %d: %s\n", packet->id, packet->data);
}

void processStream() {
    AudioPacket packets[BUFFER_SIZE];
    int num_packets = 3;

    for (int i = 0; i < num_packets; i++) {
        packets[i].id = i;
        packets[i].data = (char*)malloc(BUFFER_SIZE * sizeof(char));
        sprintf(packets[i].data, "Audio data %d", i);
    }

    for (int i = 0; i < num_packets; i++) {
        decodeAudio(&packets[i]);
    }

    // Use after free vulnerability
    for (int i = num_packets - 1; i >= 0; i--) {
        free(packets[i].data);
    }

    // Exploit the use after free
    for (int i = 0; i < num_packets; i++) {
        decodeAudio(&packets[i]); // This line is vulnerable
    }
}

int main() {
    processStream();
    return 0;
}
