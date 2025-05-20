#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CHUNK_SIZE 4

void decode(char *buffer) {
    unsigned char sample[CHUNK_SIZE];
    unsigned int i;

    for (i = 0; i < BUFFER_SIZE; i++) {
        sample[i % CHUNK_SIZE] = buffer[i];

        if (sample[i % CHUNK_SIZE] >= 255) {
            sample[(i - 1) % CHUNK_SIZE] += sample[i % CHUNK_SIZE] - 255;
        }
    }

    for (i = 0; i < CHUNK_SIZE; i++) {
        printf("%c", sample[i]);
    }
}

int main(int argc, char **argv) {
    char *input;
    size_t size;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }

    input = malloc(strlen(argv[1]) + 1);
    if (!input) {
        perror("Error allocating memory");
        return 1;
    }

    size = strncpy(input, argv[1], strlen(argv[1]) + 1);

    if (size != strlen(argv[1]) + 1) {
        fprintf(stderr, "Invalid input length.\n");
        free(input);
        return 1;
    }

    decode(input);
    free(input);
    return 0;
}
