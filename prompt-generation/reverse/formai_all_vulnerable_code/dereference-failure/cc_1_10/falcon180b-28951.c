//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Ebook;

Ebook *create_ebook() {
    Ebook *ebook = (Ebook *)malloc(sizeof(Ebook));
    ebook->lines = (Line *)malloc(sizeof(Line) * MAX_NUM_LINES);
    ebook->num_lines = 0;
    return ebook;
}

void destroy_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].line);
    }
    free(ebook->lines);
    free(ebook);
}

void add_line(Ebook *ebook, char *line) {
    if (ebook->num_lines >= MAX_NUM_LINES) {
        printf("Error: Ebook is full.\n");
        return;
    }
    ebook->lines[ebook->num_lines].line = strdup(line);
    ebook->lines[ebook->num_lines].length = strlen(line);
    ebook->num_lines++;
}

void print_ebook(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].line);
    }
}

int main() {
    Ebook *ebook = create_ebook();
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(ebook, line);
    }
    print_ebook(ebook);
    destroy_ebook(ebook);
    return 0;
}