//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#define MAX_LINE_SIZE 1024 // Maximum size of each line

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char filename[MAX_LINE_SIZE];
    int linenumber = 1; // Line number starts at 1
    int error = 0; // Flag to indicate if an error occurred

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        printf("Error: Incorrect number of arguments. Usage: %s <filename> <keyword>\n", argv[0]);
        return 1;
    }

    // Copy the filename argument to a local variable
    strcpy(filename, argv[1]);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    // Read each line of the file
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        // Remove the newline character from the end of the line
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Check if the line contains the keyword
        if (strstr(line, argv[2])!= NULL) {
            printf("Line %d: %s\n", linenumber, line);
            linenumber++;
        } else {
            linenumber++;
        }
    }

    // Close the file
    if (fclose(fp)!= 0) {
        printf("Error: Could not close file %s\n", filename);
        return 1;
    }

    return 0;
}