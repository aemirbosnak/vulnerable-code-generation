//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_LENGTH 1000

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_FILE_LENGTH], output_filename[MAX_FILE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char buffer[MAX_FILE_LENGTH];
    int key_length, file_length;

    // Prompt user for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Prompt user for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Prompt user for encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);
    key_length = strlen(key);

    // Read input file into buffer
    file_length = fread(buffer, 1, MAX_FILE_LENGTH, input_file);
    if (feof(input_file)) {
        printf("Error reading input file.\n");
        exit(1);
    }

    // Encrypt buffer using key
    for (int i = 0; i < file_length; i++) {
        if (isalpha(buffer[i])) {
            if (isupper(buffer[i])) {
                buffer[i] = tolower(buffer[i]) + key_length;
            } else {
                buffer[i] = tolower(buffer[i]) - key_length;
            }
        } else {
            buffer[i] = buffer[i];
        }
    }

    // Write encrypted buffer to output file
    fwrite(buffer, 1, file_length, output_file);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}