//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define KEY_LENGTH 8

int main() {
    char filename[MAX_LINE_LENGTH];
    char key[KEY_LENGTH];
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char encrypted_line[MAX_LINE_LENGTH];
    int line_number = 1;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open file '%s' for reading.\n", filename);
        return 1;
    }

    // Open output file
    output_file = fopen("encrypted_file.txt", "w");
    if (output_file == NULL) {
        printf("Error: could not open file 'encrypted_file.txt' for writing.\n");
        fclose(input_file);
        return 1;
    }

    // Loop through input file and encrypt each line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Convert line to uppercase
        for (int i = 0; i < strlen(line); i++) {
            line[i] = toupper(line[i]);
        }

        // Encrypt line using key
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = line[i] + key[i % KEY_LENGTH];
            }
        }

        // Write encrypted line to output file
        fprintf(output_file, "Line %d: %s\n", line_number, line);
        line_number++;
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption completed successfully.\n");
    return 0;
}