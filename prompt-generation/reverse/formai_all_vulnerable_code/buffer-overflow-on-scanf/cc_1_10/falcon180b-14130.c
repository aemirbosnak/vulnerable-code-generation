//Falcon-180B DATASET v1.0 Category: File handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    // prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // read file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: maximum number of lines exceeded.\n");
            fclose(fp);
            return 1;
        }
        lines[num_lines++].line = strdup(line);
        lines[num_lines - 1].line_num = num_lines;
    }

    // close file
    fclose(fp);

    // sort lines by length
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strlen(lines[i].line) > strlen(lines[j].line)) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // print sorted lines with line numbers
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }

    // free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }

    return 0;
}