//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to encrypt file recursively
void encryptFile(FILE* input, FILE* output, int key) {
    char line[MAX_LINE_LENGTH];
    int lineLength;

    // Read line from input file
    if (fgets(line, MAX_LINE_LENGTH, input) == NULL) {
        return;
    }
    lineLength = strlen(line);

    // Encrypt line
    for (int i = 0; i < lineLength; i++) {
        if (isalpha(line[i])) {
            line[i] = (line[i] + key - 65) % 26 + 65;
        }
    }

    // Write encrypted line to output file
    fprintf(output, "%s\n", line);

    // Recursively encrypt the rest of the file
    encryptFile(input, output, key);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int key = atoi(argv[3]);

    // Encrypt file recursively
    encryptFile(input, output, key);

    // Close input and output files
    fclose(input);
    fclose(output);

    return 0;
}