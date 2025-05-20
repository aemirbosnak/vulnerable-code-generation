#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t byte;

const char *file_name = "input.raw";
byte buffer[44100];
byte *data_ptr;

void decode_audio_frame(void) {
    if (!data_ptr) return;

    // Simulate audio decoding logic
    byte sample = *data_ptr++;
    byte noise = sample / 2;

    for (int i = 0; i < 44100; i++) {
        printf("%d\n", noise);
    }
}

int main(int argc, char **argv) {
    FILE *file = fopen(file_name, "rb");
    fread(buffer, sizeof(byte), 44100, file);
    data_ptr = buffer;

    while (1) {
        decode_audio_frame();
    }

    fclose(file);
    return 0;
}
