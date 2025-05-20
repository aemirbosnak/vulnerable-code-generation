//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the encryption key
#define KEY "mysecretkey"

// Define the maximum length of the input file name
#define MAX_FILE_NAME_LENGTH 100

// Function to encrypt the file content
void encrypt(FILE *input, FILE *output) {
    char ch;
    while ((ch = fgetc(input))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch + 13) % 26 + 'A';
        }
        else if (isdigit(ch)) {
            ch = (ch + 5) % 10 + '0';
        }
        fputc(ch, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    char input_file[MAX_FILE_NAME_LENGTH];
    char output_file[MAX_FILE_NAME_LENGTH];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Cannot open input file %s\n", input_file);
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Cannot create output file %s\n", output_file);
        fclose(input);
        return 1;
    }

    // Add the encryption key to the beginning of the output file
    fprintf(output, "%s", KEY);

    // Encrypt the file content
    encrypt(input, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("File %s encrypted successfully to %s\n", input_file, output_file);
    return 0;
}