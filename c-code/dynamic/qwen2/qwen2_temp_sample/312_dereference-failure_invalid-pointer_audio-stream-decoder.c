#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FRAME_SIZE 1024

typedef struct {
    unsigned char* data;
    int size;
} AudioFrame;

void decodeAudio(AudioFrame* frame) {
    if (frame->data == NULL) {
        printf("Error: Invalid audio frame pointer.\n");
        return;
    }

    // Simulate audio decoding process
    for (int i = 0; i < frame->size; i++) {
        frame->data[i] += 32; // Just add some arbitrary value to simulate processing
    }
}

int main() {
    AudioFrame frame;
    frame.data = NULL;
    frame.size = FRAME_SIZE;

    // Deliberate error: Dereferencing a null pointer
    int* sample = (int*)frame.data;
    *sample = 100; // This will cause a segmentation fault

    decodeAudio(&frame);

    return 0;
}
