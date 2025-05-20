//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input_file[100], output_file[100], line[1000];
    FILE *fp_in, *fp_out;

    // Get input and output file names from user
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open input and output files
    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(fp_in);
        exit(1);
    }

    // Read input file line by line and beautify HTML code
    while (fgets(line, sizeof(line), fp_in)!= NULL) {
        // Remove leading and trailing spaces from the line
        int i, j;
        for (i = 0, j = strlen(line) - 1; i < j; i++, j--) {
            if (!isspace(line[i]) &&!isspace(line[j])) {
                break;
            }
        }
        line[i] = '\0';

        // Add indentation to the line
        char *p = line;
        while (*p!= '<') {
            if (*p == '\n') {
                strcat(line, "\n    ");
            }
            p++;
        }

        // Write beautified line to output file
        fprintf(fp_out, "%s", line);
    }

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    printf("HTML code beautified successfully.\n");
    return 0;
}