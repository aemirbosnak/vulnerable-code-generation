#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_header(FILE *file) {
    char header[128];
    fread(header, 1, 128, file);
    printf("Header: %s\n", header);
}

void decode_frame(FILE *file) {
    char frame[BUFFER_SIZE];
    fread(frame, 1, BUFFER_SIZE, file);

    int i;
    for (i = 0; i < BUFFER_SIZE; i++) {
        if (frame[i] == '\0') {
            printf("Frame ended prematurely.\n");
            return;
        }

        if (i >= 10 && frame[i] >= 'A' && frame[i] <= 'Z') {
            printf("OOF: invalid character '%c' at index %d\n", frame[i], i);
        }
    }

    printf("Decoded frame:\n");
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%c", frame[i]);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];

    if (!(file = fopen(filename, "rb"))) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return 1;
    }

    read_header(file);
    decode_frame(file);

    fclose(file);
    return 0;
}
