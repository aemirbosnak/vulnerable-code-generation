//FormAI DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHAR_PER_LINE 200

int main(int argc, char** argv) {

    char filename[100];
    int max_lines = MAX_LINES;
    int max_char_per_line = MAX_CHAR_PER_LINE;

    if (argc > 1) {
        strcpy(filename, argv[1]);
    }
    else {
        printf("Enter the filename: ");
        scanf("%s", filename);
    }

    if (argc > 2) {
        max_lines = atoi(argv[2]);
    }
    else {
        printf("Enter the maximum number of lines to analyze: ");
        scanf("%d", &max_lines);
    }

    if (argc > 3) {
        max_char_per_line = atoi(argv[3]);
    }
    else {
        printf("Enter the maximum number of characters per line: ");
        scanf("%d", &max_char_per_line);
    }

    FILE* fptr;
    char line[MAX_CHAR_PER_LINE];
    char* result;
    int line_count = 0;

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return -1;
    }

    printf("Analyzing file: %s\n", filename);

    /* Reading lines of the file and printing them */
    while (fgets(line, MAX_CHAR_PER_LINE, fptr) != NULL && line_count < max_lines) {
        printf("%s", line);
        line_count++;
    }

    fclose(fptr);

    return 0;
}