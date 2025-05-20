//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *line;
    int length;
} Line;

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", argv[1]);
        exit(1);
    }

    int line_count = 0;
    Line lines[MAX_LINES];

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        if (line_count >= MAX_LINES) {
            fprintf(stderr, "Reached maximum number of lines (%d)\n", MAX_LINES);
            exit(1);
        }

        int length = strlen(buffer);
        lines[line_count].line = malloc(length + 1);
        lines[line_count].length = length;
        strcpy(lines[line_count].line, buffer);
        line_count++;
    }

    fclose(fp);

    int total_length = 0;
    int max_length = 0;
    int min_length = MAX_LINE_LENGTH;

    for (int i = 0; i < line_count; i++) {
        total_length += lines[i].length;
        if (lines[i].length > max_length) {
            max_length = lines[i].length;
        }
        if (lines[i].length < min_length) {
            min_length = lines[i].length;
        }
    }

    double avg_length = total_length / (double) line_count;

    printf("Total lines: %d\n", line_count);
    printf("Average line length: %.2f\n", avg_length);
    printf("Minimum line length: %d\n", min_length);
    printf("Maximum line length: %d\n", max_length);

    for (int i = 0; i < line_count; i++) {
        printf("%d: %s\n", i + 1, lines[i].line);
    }

    for (int i = 0; i < line_count; i++) {
        free(lines[i].line);
    }

    return 0;
}