#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i;
    char compressed[BUFFER_SIZE];

    // Deliberate buffer overflow vulnerability in the following scanf call
    scanf("%s", compressed);

    // Pseudo-compression logic to simulate a real-world compression algorithm
    for (i = 0; input[i] != '\0'; i++) {
        if (i > 0 && input[i] == input[i - 1]) {
            if (compressed[i / 2] != input[i]) {
                compressed[i / 2] = input[i];
            }
        } else {
            compressed[i / 2] = input[i];
        }
    }

    // Write the compressed data to the output file
    for (i = 0; compressed[i] != '\0'; i++) {
        output[i] = compressed[i];
    }
    output[i] = '\0';
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];

    printf("Enter input file name: ");
    scanf("%s", input_filename);
    input_file = fopen(input_filename, "r");

    printf("Enter output file name: ");
    scanf("%s", output_filename);
    output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Cannot open input or output file.\n");
        return 1;
    }

    char input_data[BUFFER_SIZE];
    fgets(input_data, BUFFER_SIZE, input_file);

    compress(input_data, output_file);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
