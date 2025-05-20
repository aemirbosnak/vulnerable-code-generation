//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

// Function to encrypt the file
void encrypt_file(FILE *file) {
    char line[MAX_LINE_SIZE];
    char encrypted_line[MAX_LINE_SIZE];
    int key = 5; // The key to use for encryption
    int i, j;

    // Read the file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Encrypt the line
        for (i = 0, j = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                encrypted_line[j] = (line[i] - 'a' + key) % 26 + 'a';
                j++;
            } else {
                encrypted_line[j] = line[i];
                j++;
            }
        }
        encrypted_line[j] = '\0';

        // Write the encrypted line to the file
        fputs(encrypted_line, file);
    }
}

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_SIZE];
    char output_filename[MAX_LINE_SIZE];

    // Get the input filename from the user
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Open the input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Get the output filename from the user
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open the output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Encrypt the input file
    encrypt_file(input_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
    return 0;
}