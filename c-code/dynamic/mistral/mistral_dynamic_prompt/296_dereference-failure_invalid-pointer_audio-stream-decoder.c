#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

void decode(byte* buffer, int size) {
    byte* ptr = malloc(size);
    byte* temp = malloc(size);
    memcpy(ptr, buffer, size);

    int i = 0;
    while (i < size) {
        byte value = ptr[i] ^ temp[i];
        if (value > 127) {
            printf("%c", value - 64); // print uppercase ASCII if value > 127
        } else {
            printf("%c", value); // print lowercase ASCII if value <= 127
        }
        i++;

        if (i < size - 1) {
            temp[i] = ptr[i + 1];
        }
    }

    free(ptr);
    free(temp);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_audio_file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fseek(file, -1, SEEK_END);
    int file_size = ftell(file) + 1;
    byte* buffer = malloc(file_size);
    fseek(file, 0, SEEK_SET);
    fread(buffer, 1, file_size, file);
    fclose(file);

    decode(buffer, file_size);

    free(buffer);
    return 0;
}
