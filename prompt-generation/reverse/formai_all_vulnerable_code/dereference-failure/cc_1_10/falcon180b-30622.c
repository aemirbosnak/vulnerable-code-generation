//Falcon-180B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

struct line {
    char *text;
    int length;
};

struct file {
    FILE *fp;
    int num_lines;
    struct line *lines;
};

int read_file(struct file *f) {
    char ch;
    int i = 0;
    while ((ch = fgetc(f->fp))!= EOF) {
        if (i >= f->num_lines) {
            f->num_lines += MAX_NUM_LINES;
            f->lines = realloc(f->lines, sizeof(struct line) * f->num_lines);
        }
        f->lines[i].text = malloc(MAX_LINE_LENGTH * sizeof(char));
        f->lines[i].length = 0;
        while (isspace(ch)) {
            ch = fgetc(f->fp);
        }
        if (ch!= EOF) {
            f->lines[i].text[f->lines[i].length++] = tolower(ch);
        }
    }
    f->lines[i].text[f->lines[i].length] = '\0';
    return i + 1;
}

void print_lines(struct file *f) {
    int i;
    for (i = 0; i < f->num_lines; i++) {
        printf("%s\n", f->lines[i].text);
    }
}

void free_file(struct file *f) {
    int i;
    for (i = 0; i < f->num_lines; i++) {
        free(f->lines[i].text);
    }
    free(f->lines);
    fclose(f->fp);
}

int main(int argc, char **argv) {
    FILE *fp;
    struct file f;
    int i;

    if (argc!= 2) {
        printf("Usage: %s file\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    f.fp = fp;
    f.num_lines = 0;
    f.lines = NULL;

    read_file(&f);

    print_lines(&f);

    free_file(&f);

    return 0;
}