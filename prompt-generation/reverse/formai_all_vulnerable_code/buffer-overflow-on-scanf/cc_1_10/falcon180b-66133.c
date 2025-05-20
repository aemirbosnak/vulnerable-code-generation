//Falcon-180B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_number;
} Line;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    int i;

    // prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file for reading
    file = fopen(filename, "r");

    // check if file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // read lines from file and store in array
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // allocate memory for line and copy it
        lines[num_lines].line = malloc(strlen(line) + 1);
        strcpy(lines[num_lines].line, line);

        // set line number
        lines[num_lines].line_number = num_lines + 1;

        // increment number of lines
        num_lines++;
    }

    // close file
    fclose(file);

    // print lines in reverse order
    for (i = num_lines - 1; i >= 0; i--) {
        printf("%d: %s", lines[i].line_number, lines[i].line);
    }

    // free memory allocated for lines
    for (i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }

    return 0;
}