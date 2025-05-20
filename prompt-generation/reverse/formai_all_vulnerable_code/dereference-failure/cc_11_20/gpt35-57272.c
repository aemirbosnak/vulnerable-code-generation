//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000 // Maximum length of a line

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide the name of the HTML file to be beautified");
        exit(1);
    }

    char *filename = argv[1];
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Unable to open file %s", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char output[MAX_LINE_LENGTH * 10]; // A buffer to hold all the lines of the beautified HTML

    while (fgets(line, MAX_LINE_LENGTH, fptr) != NULL) {
        char *trimmed_line = malloc(strlen(line) * sizeof(char));
        int trimmed_line_size = 0;

        // Remove leading and trailing whitespaces from the line
        int i = 0;

        while (line[i] == ' ' || line[i] == '\t') {
            i++;
        }

        int j = strlen(line) - 1;

        while (line[j] == ' ' || line[j] == '\t' || line[j] == '\n' || line[j] == '\r') {
            j--;
        }

        for (int k = i; k <= j; k++) {
            trimmed_line[trimmed_line_size++] = line[k];
        }

        trimmed_line[trimmed_line_size] = '\0';

        // Determine the level of indentation for the line
        int level = 0;

        for (int k = 0; k < strlen(trimmed_line); k++) {
            if (trimmed_line[k] == '<') {
                if (trimmed_line[k+1] == '/') {
                    level--;
                }

                for (int l = 0; l < level; l++) {
                    strcat(output, "\t");
                }

                if (trimmed_line[k+1] != '/') {
                    level++;
                }
            }

            strncat(output, &trimmed_line[k], 1);

            if (trimmed_line[k] == '>') {
                strcat(output, "\n");
            }
        }

        free(trimmed_line);
    }

    printf("%s", output);

    fclose(fptr);

    return 0;
}