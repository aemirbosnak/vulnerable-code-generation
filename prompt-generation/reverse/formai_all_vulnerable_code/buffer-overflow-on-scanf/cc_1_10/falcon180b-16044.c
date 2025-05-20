//Falcon-180B DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    int line_number;
} Line;

int main() {
    FILE *file;
    char input_file[100];
    char output_file[100];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    int i;

    // prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // open input file for reading
    file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // read lines from input file and store in array
    while (fgets(lines[num_lines].line, MAX_LINE_LENGTH, file)!= NULL) {
        num_lines++;
    }

    // close input file
    fclose(file);

    // open output file for writing
    file = fopen(output_file, "w");
    if (file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // write lines to output file in reverse order
    for (i = num_lines - 1; i >= 0; i--) {
        fprintf(file, "%d: %s", lines[i].line_number, lines[i].line);
    }

    // close output file
    fclose(file);

    printf("Done.\n");

    return 0;
}