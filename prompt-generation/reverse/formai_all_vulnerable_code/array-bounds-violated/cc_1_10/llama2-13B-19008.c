//LLAMA2-13B DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_NAME_LENGTH 256
#define MAX_LINE_LENGTH 1024

// Structure to hold the name and line number of the current line being edited
typedef struct {
    char name[MAX_NAME_LENGTH];
    int line;
} line_info_t;

// Array to store the line information for each file
line_info_t lines[10];

// Function to read a line from the input file and add it to the line array
void read_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    // Trim the newline character from the end of the line
    line[strcspn(line, "\n")] = 0;
    // Split the line into a name and a line number
    char *name = strtok(line, " ");
    int line_num = atoi(strtok(NULL, " "));
    // Add the line information to the array
    lines[sizeof(lines) - 1] = (line_info_t) {
        .name = name,
        .line = line_num
    };
}

// Function to write the line information to the output file
void write_line(FILE *file, line_info_t line) {
    fprintf(file, "%s %d\n", line.name, line.line);
}

int main(void) {
    // Open the input and output files
    FILE *ifile = fopen("input.txt", "r");
    FILE *ofile = fopen("output.txt", "w");
    if (ifile == NULL || ofile == NULL) {
        perror("Error opening files");
        return 1;
    }

    // Read the line information from the input file
    while (fgets(lines[sizeof(lines) - 1].name, MAX_LINE_LENGTH, ifile) != NULL) {
        read_line(ifile);
    }

    // Write the line information to the output file
    for (int i = 0; i < sizeof(lines); i++) {
        write_line(ofile, lines[i]);
    }

    // Close the files
    fclose(ifile);
    fclose(ofile);

    return 0;
}