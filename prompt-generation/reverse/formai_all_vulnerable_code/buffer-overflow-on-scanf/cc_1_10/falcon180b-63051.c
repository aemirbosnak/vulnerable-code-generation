//Falcon-180B DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    char input_file[MAX_LINE_LENGTH];
    char output_file[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *input_fp, *output_fp;
    int line_num = 0;
    int error_count = 0;
    int max_errors = 10; // maximum number of errors before exiting

    // Prompt user for input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Open output file
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_fp);
        return 1;
    }

    // Loop through input file
    while (fgets(line, MAX_LINE_LENGTH, input_fp)!= NULL) {
        line_num++;

        // Check for errors in line
        char *error_ptr = strchr(line, ':');
        if (error_ptr == NULL || error_ptr == line) {
            printf("Error on line %d: invalid syntax.\n", line_num);
            fprintf(output_fp, "Error on line %d: invalid syntax.\n", line_num);
            error_count++;
        } else {
            // Write line to output file if no errors
            fprintf(output_fp, "%s", line);
        }
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    // Exit with error code if too many errors
    if (error_count >= max_errors) {
        printf("Too many errors, exiting program.\n");
        return 1;
    } else {
        printf("Program completed successfully.\n");
        return 0;
    }
}