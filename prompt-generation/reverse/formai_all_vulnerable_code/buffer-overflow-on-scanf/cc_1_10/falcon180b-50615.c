//Falcon-180B DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100000

int main() {
    FILE *input_file, *output_file;
    char input_filename[50], output_filename[50];
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    // Open input file for reading
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        exit(1);
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_count++;

        // Reverse the line
        int i, j;
        for (i = 0, j = strlen(line) - 1; i < j; i++, j--) {
            char temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }

        // Write reversed line to output file
        fputs(line, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    // Print line count
    printf("Line count: %d\n", line_count);

    return 0;
}