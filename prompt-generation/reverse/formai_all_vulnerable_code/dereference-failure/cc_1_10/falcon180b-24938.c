//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1000

typedef struct {
    char *text;
    int line_number;
} Line;

typedef struct {
    Line **lines;
    int num_lines;
} Ebook;

Ebook *ebook_create() {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void ebook_destroy(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i]->text);
        free(ebook->lines[i]);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_add_line(Ebook *ebook, const char *text) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->line_number = ebook->num_lines;
    ebook->lines = realloc(ebook->lines, sizeof(Line *) * (ebook->num_lines + 1));
    ebook->lines[ebook->num_lines] = line;
    ebook->num_lines++;
}

void ebook_print(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%d: %s\n", ebook->lines[i]->line_number, ebook->lines[i]->text);
    }
}

int main() {
    Ebook *ebook = ebook_create();

    ebook_add_line(ebook, "Two households, both alike in dignity,");
    ebook_add_line(ebook, "In fair Verona, where we lay our scene,");
    ebook_add_line(ebook, "From ancient grudge break to new mutiny,");
    ebook_add_line(ebook, "Where civil blood makes civil hands unclean.");

    ebook_print(ebook);

    ebook_destroy(ebook);

    return 0;
}