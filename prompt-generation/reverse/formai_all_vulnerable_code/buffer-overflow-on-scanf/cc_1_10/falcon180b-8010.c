//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
// This is a C File Encryptor program that uses the Caesar cipher algorithm to encrypt the contents of a file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100

int main() {
    char input_file_name[MAX_LINE_LENGTH];
    char output_file_name[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *input_file, *output_file;
    int key_length, i;

    // Get the name of the input file
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    // Get the name of the output file
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    // Get the encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Get the length of the encryption key
    key_length = strlen(key);

    // Open the input and output files
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Read and encrypt each line of the input file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Convert the line to uppercase
        for (i = 0; i < strlen(line); i++) {
            line[i] = toupper(line[i]);
        }

        // Encrypt the line using the Caesar cipher algorithm
        int j = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = ((line[i] - 'A' + key_length - 1) % 26) + 'A';
            } else {
                line[i] = line[i];
            }
        }

        // Write the encrypted line to the output file
        fputs(line, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}