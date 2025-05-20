#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

void compress_file(const char* input_file, const char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = fscanf(input, "%s", buffer)) != EOF) {
        // Vulnerable to buffer overflow if input exceeds BUFFER_SIZE
        fprintf(output, "%s", buffer);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    compress_file(argv[1], argv[2]);

    return 0;
}
