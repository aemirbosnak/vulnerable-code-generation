//Falcon-180B DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *input_file, *output_file;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    char filename[50];
    char output_filename[50];
    int i;

    // Prompt user for input file name
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Open input file for reading
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read lines from input file and store in array
    while (fgets(lines[num_lines].line, MAX_LINE_LENGTH, input_file)!= NULL) {
        num_lines++;
    }
    fclose(input_file);

    // Prompt user for output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open output file for writing
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Write lines to output file in reverse order
    for (i = num_lines - 1; i >= 0; i--) {
        fprintf(output_file, "%d: %s", lines[i].line_num, lines[i].line);
    }

    // Close output file
    fclose(output_file);

    return 0;
}