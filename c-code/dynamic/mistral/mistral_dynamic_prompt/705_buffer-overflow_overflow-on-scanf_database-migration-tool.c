#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void migrate_data(char *input_file, char *output_file) {
    FILE *input, *output;
    char buffer[MAX_BUFFER_SIZE];

    input = fopen(input_file, "r");
    output = fopen(output_file, "w");

    while (fgets(buffer, sizeof(buffer), input)) {
        // Buffer overflow vulnerability here
        fprintf(output, "%s", buffer);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: migrate input_file output_file\n");
        return 1;
    }

    migrate_data(argv[1], argv[2]);

    return 0;
}
