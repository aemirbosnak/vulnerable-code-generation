//Falcon-180B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_LINE_LENGTH 80

int main() {
    FILE *input_file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int num_lines = 0;
    int num_errors = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;

        // Check for errors
        if (line[0]!= '\n') {
            printf("Error: Line %d is not terminated with a newline character.\n", line_number);
            num_errors++;
        } else if (line[strlen(line) - 1]!= '\n') {
            printf("Error: Line %d is not terminated with a newline character.\n", line_number);
            num_errors++;
        } else if (strlen(line) > MAX_LINE_LENGTH) {
            printf("Error: Line %d is too long.\n", line_number);
            num_errors++;
        }

        // Count lines
        num_lines++;
    }

    // Close file
    fclose(input_file);

    // Print results
    printf("Total lines: %d\n", num_lines);
    printf("Total errors: %d\n", num_errors);

    return 0;
}