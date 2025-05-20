//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1000

typedef struct {
    char *line;
    int count;
} LineCount;

void read_log_file(FILE *fp, LineCount *counts, int num_lines) {
    char line[MAX_LINE_LEN];
    int i = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (i >= num_lines) {
            break;
        }

        counts[i].line = strdup(line);
        counts[i].count = 1;
        i++;
    }
}

void print_counts(LineCount *counts, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s: %d\n", counts[i].line, counts[i].count);
    }
}

int main() {
    FILE *fp;
    char log_file[MAX_LINE_LEN];
    LineCount counts[MAX_LINES];
    int num_lines = 0;

    // Get the log file name from the user
    printf("Enter the name of the log file: ");
    scanf("%s", log_file);

    // Open the log file
    fp = fopen(log_file, "r");

    if (fp == NULL) {
        printf("Error: could not open log file.\n");
        return 1;
    }

    // Read the log file
    read_log_file(fp, counts, MAX_LINES);

    // Print the line counts
    printf("Line counts:\n");
    print_counts(counts, num_lines);

    // Close the log file
    fclose(fp);

    return 0;
}