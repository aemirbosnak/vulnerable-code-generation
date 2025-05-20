#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

void decode_wav(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int size;

    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Decoding audio stream from %s...\n", filename);

    while ((size = fscanf(file, "%s", buffer)) != EOF) {
        if (size > BUFFER_SIZE) {
            printf("Buffer overflow detected!\n");
            break;
        }

        // TODO: Process the buffer data to decode the audio stream...

        // Here's the vulnerable part, fscanf can read more than BUFFER_SIZE bytes if the input is too large
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    decode_wav(argv[1]);
    return 0;
}
