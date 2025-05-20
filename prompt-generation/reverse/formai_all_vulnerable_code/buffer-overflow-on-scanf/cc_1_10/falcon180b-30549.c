//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_SIZE], output_filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    int binary_value = 0;
    int decimal_value = 0;
    int i = 0;
    int j = 0;

    // Get input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        // Convert each line to binary
        for (i = 0; line[i]!= '\0'; i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                decimal_value = decimal_value * 10 + (line[i] - '0');
            } else {
                printf("Error: Invalid character found in input file.\n");
                exit(1);
            }
        }

        // Write binary value to output file
        for (j = 0; j < 8; j++) {
            if (binary_value % 2 == 0) {
                fprintf(output_file, "0");
            } else {
                fprintf(output_file, "1");
            }
            binary_value /= 2;
        }
        fprintf(output_file, "\n");
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Binary conversion completed successfully.\n");

    return 0;
}