#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input, char *output) {
    int *data = (int*)malloc(strlen(input) * sizeof(int));
    int *ptr = data;

    for (int i = 0; input[i]; ++i) {
        *ptr++ = (int)input[i];
    }

    *ptr = -1; // Dereference failure intentionally added

    for (int i = 0; data[i] != -1; ++i) {
        int current = data[i];
        int count = 1;
        if (i + 1 < strlen(data) && data[i + 1] == current) {
            while (data[i + 1] == current && i + 1 < strlen(data)) {
                i++;
                count++;
            }
        }
        output[i] = (char)(count > 99 ? '?' : count);
        output[i] += current;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./compression_tool <input_file> <output_file>\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Failed to open files");
        return 1;
    }

    char input_buffer[1024];
    char output_buffer[1024];

    while (fgets(input_buffer, sizeof(input_buffer), input)) {
        compress(input_buffer, output_buffer);
        fputs(output_buffer, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}
