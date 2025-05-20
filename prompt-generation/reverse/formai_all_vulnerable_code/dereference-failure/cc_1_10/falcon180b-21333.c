//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024

typedef struct {
    char *filename;
    FILE *fp;
    int line_num;
} Ebook;

Ebook *ebook_open(const char *filename) {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->filename = strdup(filename);
    ebook->fp = fopen(filename, "r");
    if (ebook->fp == NULL) {
        fprintf(stderr, "Error: Could not open ebook file '%s'\n", filename);
        exit(1);
    }
    ebook->line_num = 1;
    return ebook;
}

char *ebook_readline(Ebook *ebook) {
    char *line = malloc(MAX_LINE_LEN);
    fgets(line, MAX_LINE_LEN, ebook->fp);
    int len = strlen(line);
    if (len > 0 && line[len - 1] == '\n') {
        line[--len] = '\0';
    }
    ebook->line_num++;
    return line;
}

void ebook_close(Ebook *ebook) {
    fclose(ebook->fp);
    free(ebook->filename);
    free(ebook);
}

void ebook_print(Ebook *ebook, int start_line, int end_line) {
    rewind(ebook->fp);
    int line_num = 1;
    while (line_num <= start_line - 1) {
        ebook_readline(ebook);
        line_num++;
    }
    while (line_num <= end_line) {
        char *line = ebook_readline(ebook);
        printf("%4d: %s", line_num, line);
        line_num++;
    }
}

int main() {
    Ebook *ebook = ebook_open("example.txt");
    ebook_print(ebook, 1, 10);
    ebook_close(ebook);
    return 0;
}