//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_COLOR_NAMES 7

// Color name to code mapping
struct color_code {
    char *name;
    char code[7];
};

struct color_code color_codes[] = {
    {"black", "\033[30m"},
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"yellow", "\033[33m"},
    {"blue", "\033[34m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"}
};

int num_color_codes = sizeof(color_codes) / sizeof(struct color_code);

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_LINE_LENGTH], output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Get input and output filenames from user
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Open input and output files
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file '%s'\n", input_filename);
        exit(1);
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file '%s'\n", output_filename);
        fclose(input_file);
        exit(2);
    }

    // Loop through input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;

        // Convert color codes in line to ANSI escape sequences
        int i, j;
        for (i = 0; i < num_color_codes; i++) {
            j = 0;
            while ((j < strlen(line)) && (strncmp(&line[j], color_codes[i].name, strlen(color_codes[i].name)) == 0)) {
                // Found a color code, replace with ANSI escape sequence
                strncat(&line[j], color_codes[i].code, strlen(color_codes[i].code));
                j += strlen(color_codes[i].code);
            }
        }

        // Write modified line to output file
        fprintf(output_file, "%s", line);
    }

    // Close files and exit
    fclose(input_file);
    fclose(output_file);
    printf("Conversion complete. %d line(s) processed.\n", line_number);
    return 0;
}