#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress_data(char* input_data) {
    int i, count_chars[256];
    char* compressed_data;
    char* output = malloc(BUFFER_SIZE * sizeof(char));
    if (!output) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    memset(count_chars, 0, sizeof(count_chars));
    for (i = 0; input_data[i]; ++i)
        count_chars[(unsigned char)input_data[i]]++;

    int pos = 0;
    for (i = 0; i < 256; ++i) {
        if (count_chars[i]) {
            sprintf(output + pos, "%d%c", count_chars[i], i);
            pos += sprintf(output + pos, "%c", count_chars[i] > 9 ? ',' : ' ');
            pos += count_chars[i];
        }
    }

    compressed_data = realloc(output, pos);
    if (!compressed_data) {
        perror("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }

    printf("Compressed data: %s\n", compressed_data);
    free(output);
}

int main(int argc, char** argv) {
    char buffer[BUFFER_SIZE];
    printf("Enter data to compress (up to %d characters):\n", BUFFER_SIZE);
    if (sscanf(getchar(), "%s", buffer) == EOF) {
        printf("Error reading input\n");
        return 1;
    }

    compress_data(buffer);
    return 0;
}
