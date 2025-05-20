//Falcon-180B DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char input_file_path[MAX_LINE_LENGTH];
    char output_file_path[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    // Get input file path from user
    printf("Enter input file path: ");
    scanf("%s", input_file_path);

    // Open input file for reading
    FILE *input_file = fopen(input_file_path, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Get output file path from user
    printf("Enter output file path: ");
    scanf("%s", output_file_path);

    // Open output file for writing
    FILE *output_file = fopen(output_file_path, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Process each line of input file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Reverse the string
        char *start = line;
        char *end = line + strlen(line) - 1;
        while (start < end) {
            char temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }

        // Write reversed string to output file
        fprintf(output_file, "%s\n", line);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}