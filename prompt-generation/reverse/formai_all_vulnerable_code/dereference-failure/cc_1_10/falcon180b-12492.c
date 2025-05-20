//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 1000

int main() {
    char input_file[MAX_STRING];
    char output_file[MAX_STRING];
    char key[MAX_STRING];
    char buffer[MAX_STRING];
    FILE *input, *output;
    int i, j, key_len, read_bytes;

    // Get the input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Get the output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Get the encryption key
    printf("Enter encryption key: ");
    scanf("%s", key);
    key_len = strlen(key);

    // Open the input file
    input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    // Open the output file
    output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    // Read the input file and encrypt it
    while ((read_bytes = fread(buffer, 1, MAX_STRING, input)) > 0) {
        for (i = 0; i < read_bytes; i++) {
            buffer[i] ^= key[i % key_len];
        }
        fwrite(buffer, 1, read_bytes, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("File encryption completed successfully.\n");

    return 0;
}