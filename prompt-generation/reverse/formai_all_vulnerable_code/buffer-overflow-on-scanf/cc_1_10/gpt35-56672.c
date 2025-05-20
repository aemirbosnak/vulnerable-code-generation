//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Declare variables
    FILE *fp_input, *fp_output;
    char input_file[100], output_file[100], line[100];
    int line_len, i;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input and output files
    fp_input = fopen(input_file, "r");
    fp_output = fopen(output_file, "w");

    // Check if files exist
    if (fp_input == NULL) {
        printf("Input file does not exist.\n");
        exit(1);
    }
    if (fp_output == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Loop through each line in the input file
    while (fgets(line, sizeof(line), fp_input)) {
        line_len = strlen(line);

        // Loop through each character in the line
        for (i = 0; i < line_len; i++) {
            // Check for HTML tag opening
            if (line[i] == '<') {
                // Add newline before opening tag
                fprintf(fp_output, "\n");
                fprintf(fp_output, "<");

                // Check for tag closing
                while (line[i] != '>') {
                    // Add each character to output
                    fprintf(fp_output, "%c", line[i]);
                    i++;
                }

                // Add final character (closing tag) and newline
                fprintf(fp_output, ">\n");
            }
            else {
                // Add character to output
                fprintf(fp_output, "%c", line[i]);
            }
        }
    }

    // Close files
    fclose(fp_input);
    fclose(fp_output);

    return 0;
}