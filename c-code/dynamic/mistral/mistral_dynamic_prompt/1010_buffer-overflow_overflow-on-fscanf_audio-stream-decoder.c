#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(FILE *stream) {
    unsigned char buffer[BUFFER_SIZE];
    unsigned char *data = malloc(BUFFER_SIZE);
    size_t size = 0;

    while (fscanf(stream, "%s", buffer) != EOF) {
        size_t len = strlen(buffer);
        memcpy(data + size, buffer, len);
        size += len;

        // Assuming it's a RAW audio data
        if (size >= BUFFER_SIZE) {
            printf("Playing decoded audio data:\n");
            printf("%s\n", data);
            free(data);
            exit(EXIT_SUCCESS);
        }
    }
}

int main(int argc, char **argv) {
    FILE *file = fopen(argc > 1 ? argv[1] : "input.raw", "r");
    if (!file) {
        fprintf(stderr, "Failed to open input file.\n");
        return EXIT_FAILURE;
    }

    decode_audio_stream(file);

    fclose(file);
    return EXIT_SUCCESS;
}
