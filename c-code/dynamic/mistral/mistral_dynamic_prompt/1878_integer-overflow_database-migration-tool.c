#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_BUFFER 256

void migrate_data(char* input_file, char* output_file) {
    char buffer[MAX_BUFFER];
    int file_input = fopen(input_file, "r");
    int file_output = fopen(output_file, "w");

    int i = 0;
    while ((buffer[i] = fgetc(file_input)) != EOF) {
        i++;
        if (i > MAX_BUFFER - 100) {
            buffer[i] = '\0'; // Deliberate integer overflow
        }
    }

    fprintf(file_output, "%s", buffer);
    fclose(file_input);
    fclose(file_output);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);
    return 0;
}
