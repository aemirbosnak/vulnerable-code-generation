//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    char *result = line;
    int len = 0;
    int c;

    while ((c = fgetc(file))!= EOF && len < MAX_LINE_LENGTH - 1) {
        if (!isspace(c)) {
            *result = c;
            result++;
            len++;
        }
    }

    *result = '\0';
    return line;
}

void write_line(FILE *file, const char *line) {
    fprintf(file, "%s", line);
}

void process_file(const char *filename) {
    FILE *file;
    char *line;

    file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while ((line = read_line(file))!= NULL) {
        char *word = strtok(line, " ");
        while (word!= NULL) {
            write_line(stdout, word);
            word = strtok(NULL, " ");
        }
        write_line(stdout, "\n");
    }

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    process_file(argv[1]);

    return 0;
}