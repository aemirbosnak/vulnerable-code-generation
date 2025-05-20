//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char* filename;
    FILE* fp;
    int line_number;
} Ebook;

Ebook* ebook_open(const char* filename) {
    Ebook* ebook = malloc(sizeof(Ebook));
    ebook->filename = strdup(filename);
    ebook->fp = fopen(filename, "r");
    if (ebook->fp == NULL) {
        printf("Error opening ebook file '%s'\n", filename);
        exit(1);
    }
    ebook->line_number = 0;
    return ebook;
}

void ebook_close(Ebook* ebook) {
    if (ebook->fp!= NULL) {
        fclose(ebook->fp);
    }
    free(ebook->filename);
    free(ebook);
}

char* ebook_read_line(Ebook* ebook) {
    char* line = malloc(MAX_LINE_SIZE);
    fgets(line, MAX_LINE_SIZE, ebook->fp);
    ebook->line_number++;
    return line;
}

void ebook_print_line(Ebook* ebook, int linenumber) {
    char* line = ebook_read_line(ebook);
    printf("%d: %s", linenumber, line);
    free(line);
}

int main() {
    Ebook* ebook = ebook_open("example.txt");

    printf("Contents of ebook:\n");
    for (int i = 0; i < 10; i++) {
        ebook_print_line(ebook, i);
    }

    ebook_close(ebook);
    return 0;
}