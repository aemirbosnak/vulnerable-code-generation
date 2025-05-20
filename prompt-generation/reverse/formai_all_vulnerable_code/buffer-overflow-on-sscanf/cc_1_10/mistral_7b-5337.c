//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"

void process_line(char *line) {
    int count = 0;
    char *word = malloc(strlen(line) * sizeof(char));
    char *ptr = line;

    while (sscanf(ptr, "%s", word) != EOF) {
        if (strcmp(word, "happy") == 0) {
            count++;
        }
        ptr += strlen(word) + 1;
        free(word);
    }

    free(word);
    fprintf(stdout, "Line: %s, Count: %d\n", line, count);

    FILE *fp_out = fopen(FILE_OUT, "a");
    if (fp_out == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        exit(1);
    }

    fprintf(fp_out, "Line: %s, Count: %d\n", line, count);
    fclose(fp_out);
}

int main() {
    FILE *fp_in = fopen(FILE_IN, "r");
    if (fp_in == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), fp_in) != NULL) {
        process_line(line);
    }

    fclose(fp_in);
    return 0;
}