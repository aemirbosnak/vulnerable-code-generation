//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_SIZE];
    char encrypted_line[MAX_LINE_SIZE];
    int line_num = 0;

    // Read each line of the input file
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        // Encrypt the line
        for (int i = 0; line[i]!= '\0'; i++) {
            if (isalpha(line[i])) {
                line[i] = 'a' + ((line[i] - 'a') + 13) % 26;
            }
        }

        // Write the encrypted line to the output file
        fprintf(output_file, "%s", line);
        line_num++;
    }

    // Print the number of lines encrypted
    printf("Encrypted %d lines\n", line_num);
}

int main() {
    char input_filename[MAX_LINE_SIZE];
    char output_filename[MAX_LINE_SIZE];

    // Get the input file name from the user
    printf("Enter input file name: ");
    scanf("%s", input_filename);

    // Open the input file
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    // Get the output file name from the user
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open the output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(input_file, output_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}