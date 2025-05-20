//Falcon-180B DATASET v1.0 Category: Error handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    int lineno = 0;

    // Check if the correct number of arguments have been provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Loop through each line in the file
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        lineno++;

        // Check if the line is blank or contains only whitespace characters
        if (line[0] == '\n' || strspn(line, " \t\n\r\f\v") == strlen(line)) {
            continue;
        }

        // Check if the line contains any non-printable characters
        if (strpbrk(line, "\a\b\t\n\r\f\v")!= NULL) {
            fprintf(stderr, "Error on line %d: Invalid characters found\n", lineno);
            exit(EXIT_FAILURE);
        }

        // Check if the line is too long
        if (strlen(line) > MAX_LINE_SIZE - 1) {
            fprintf(stderr, "Error on line %d: Line is too long\n", lineno);
            exit(EXIT_FAILURE);
        }

        // Do something with the line (in this case, just print it)
        printf("Line %d: %s", lineno, line);
    }

    // Close the file
    if (fclose(fp)!= 0) {
        fprintf(stderr, "Error closing file '%s': %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return 0;
}