//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to calculate the checksum of a line of text
unsigned int calculate_checksum(char* line) {
    unsigned int checksum = 0;
    int i;

    for (i = 0; i < strlen(line); i++) {
        checksum += line[i];
    }

    return checksum;
}

// Function to validate the checksum of a line of text
int validate_checksum(char* line, unsigned int expected_checksum) {
    unsigned int calculated_checksum = calculate_checksum(line);

    if (calculated_checksum == expected_checksum) {
        return 1;
    }

    return 0;
}

int main() {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    FILE* input_file = NULL;
    FILE* output_file = NULL;

    // Open input file
    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen("output.txt", "w");

    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;

        // Validate checksum of each line
        if (validate_checksum(line, line_number)) {
            fprintf(output_file, "%s", line);
        } else {
            printf("Error: Invalid checksum on line %d.\n", line_number);
        }
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}