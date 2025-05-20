#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int count = 0;

    while (sscanf(input, "%50s", buffer) != EOF) {
        strcat(output, buffer);
        strcat(output, " ");
        count++;
        input += 51; // Move input pointer ahead by more than the buffer size (50 + 1 for space)
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char compressed[BUFFER_SIZE * 2];
    compress(argv[1], compressed);
    printf("Compressed string: %s\n", compressed);

    return 0;
}
