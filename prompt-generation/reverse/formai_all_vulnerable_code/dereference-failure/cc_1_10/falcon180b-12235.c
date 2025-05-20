//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *filename;
    FILE *file;
    char *line;
    int line_number;
} Ebook;

Ebook *ebook_open(char *filename) {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->filename = filename;
    ebook->file = fopen(filename, "r");
    ebook->line = malloc(MAX_LINE_LENGTH);
    ebook->line_number = 1;
    return ebook;
}

void ebook_close(Ebook *ebook) {
    fclose(ebook->file);
    free(ebook->line);
    free(ebook);
}

int ebook_readline(Ebook *ebook) {
    char c;
    int i = 0;
    while ((c = fgetc(ebook->file))!= EOF && i < MAX_LINE_LENGTH) {
        ebook->line[i++] = c;
    }
    ebook->line[i] = '\0';
    return i;
}

int ebook_read(Ebook *ebook) {
    int chars_read = ebook_readline(ebook);
    if (chars_read == 0) {
        return EOF;
    }
    return ebook->line[0];
}

int main() {
    Ebook *ebook = ebook_open("ebook.txt");
    while ((int)ebook_read(ebook)!= EOF) {
        printf("%d: %s\n", ebook->line_number, ebook->line);
        ebook->line_number++;
    }
    ebook_close(ebook);
    return 0;
}