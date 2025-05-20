//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILE_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_file_name[MAX_FILE_NAME_LENGTH], output_file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    char line[MAX_LINE_LENGTH];
    int key_length, line_length, i;

    // Check if the correct number of arguments have been provided
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    // Set the input and output file names
    strcpy(input_file_name, argv[1]);
    strcpy(output_file_name, argv[2]);

    // Set the encryption key
    strcpy(key, argv[3]);
    key_length = strlen(key);

    // Open the input and output files
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Read each line from the input file, encrypt it, and write it to the output file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_length = strlen(line);

        // Encrypt the line
        for (i = 0; i < line_length; i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]) + key[i % key_length];
            }
        }

        // Write the encrypted line to the output file
        fputs(line, output_file);
    }

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");
    return 0;
}