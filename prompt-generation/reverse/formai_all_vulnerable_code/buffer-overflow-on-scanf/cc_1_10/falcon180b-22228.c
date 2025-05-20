//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1000

// Function to encrypt the input file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];
    int i;
    bool is_encrypted = false;

    // Read the input file
    while (fgets(input_buffer, BUFFER_SIZE, input_file)!= NULL) {
        // Check if the input buffer contains any non-encrypted characters
        for (i = 0; input_buffer[i]!= '\0'; i++) {
            if (!isalpha(input_buffer[i]) &&!isspace(input_buffer[i])) {
                is_encrypted = true;
                break;
            }
        }

        // Encrypt the input buffer if it contains non-encrypted characters
        if (is_encrypted) {
            for (i = 0; input_buffer[i]!= '\0'; i++) {
                if (isalpha(input_buffer[i])) {
                    output_buffer[i] = input_buffer[i] + 13;
                } else {
                    output_buffer[i] = input_buffer[i];
                }
            }
        } else {
            strcpy(output_buffer, input_buffer);
        }

        // Write the encrypted buffer to the output file
        fputs(output_buffer, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_file_name[100], output_file_name[100];

    // Get the input and output file names from the user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    // Open the input and output files
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Encrypt the input file and write the encrypted data to the output file
    encrypt_file(input_file, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");

    return 0;
}