#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void handle_input(char* buffer) {
    FILE* stream = fopen(buffer, "rb");
    if (!stream) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    char chunk[MAX_BUFFER];
    size_t chunk_size;

    while ((chunk_size = fread(chunk, 1, MAX_BUFFER, stream)) > 0) {
        // Raw audio data processing here
        printf("Received chunk of size: %ld\n", chunk_size);
    }

    fclose(stream);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_BUFFER];
    printf("Enter the input file name (max size %d): ", MAX_BUFFER);
    scanf("%s", input_file);

    handle_input(input_file);

    return 0;
}
