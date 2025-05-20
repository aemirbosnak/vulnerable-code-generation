//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000

typedef struct {
    char line[MAX_LINE_LENGTH];
    int linenum;
} Line;

int main() {
    FILE *fp;
    Line lines[MAX_NUM_LINES];
    int numlines = 0;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read lines from file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (numlines >= MAX_NUM_LINES) {
            printf("Error: too many lines in file '%s'\n", filename);
            exit(1);
        }
        lines[numlines].linenum = numlines + 1;
        strcpy(lines[numlines].line, line);
        numlines++;
    }

    // Sort lines by length
    for (int i = 0; i < numlines - 1; i++) {
        for (int j = i + 1; j < numlines; j++) {
            if (strlen(lines[j].line) < strlen(lines[i].line)) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Print sorted lines
    printf("Sorted lines:\n");
    for (int i = 0; i < numlines; i++) {
        printf("%d: %s\n", lines[i].linenum, lines[i].line);
    }

    // Close file
    fclose(fp);

    return 0;
}