#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct AudioPacket {
    int size;
    char data[1];
} AudioPacket;

AudioPacket* decodeAudioPacket(int packetSize) {
    return (AudioPacket*)malloc(sizeof(AudioPacket) + packetSize);
}

void playAudioPacket(AudioPacket* packet) {
    printf("Playing audio packet with size: %d\n", packet->size);
    // Simulate playing audio
}

int main() {
    AudioPacket* currentPacket = decodeAudioPacket(1024);
    playAudioPacket(currentPacket);

    // Free the memory
    free(currentPacket);

    // Use-after-free vulnerability
    playAudioPacket(currentPacket);

    return 0;
}
