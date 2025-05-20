//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *text;
    int length;
} TextLine;

void read_file(const char *filename, TextLine **lines, int *line_count) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        (*lines)[i] = (TextLine) {.text = strdup(line),.length = strlen(line) };
        i++;
    }

    (*line_count) = i;
    fclose(file);
}

void print_line(const TextLine *line) {
    printf("%s\n", line->text);
}

int main() {
    TextLine *lines;
    int line_count;

    read_file("example.txt", &lines, &line_count);

    for (int i = 0; i < line_count; i++) {
        print_line(&lines[i]);
    }

    for (int i = 0; i < line_count; i++) {
        free(lines[i].text);
    }
    free(lines);

    return 0;
}