#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void process_audio_frame(byte *frame, int len) {
    int buffer[4];
    int i;

    for (i = 0; i < len; i++) {
        buffer[i % 4] += frame[i] * 32768; // Integer overflow
    }

    for (i = 0; i < 4; i++) {
        if (buffer[i] > 32767) { // UB here since we haven't checked if buffer[i] is actually an int
            buffer[i] = 32767;
        }
        printf("Buffer[%d] = %d\n", i, buffer[i]);
    }
}

int main() {
    FILE *file = fopen("input.raw", "rb");
    byte *frame;
    int len;

    while ((len = fread(frame = malloc(1024), sizeof(byte), 1024, file)) > 0) {
        process_audio_frame(frame, len);
        free(frame);
    }

    fclose(file);
    return 0;
}
