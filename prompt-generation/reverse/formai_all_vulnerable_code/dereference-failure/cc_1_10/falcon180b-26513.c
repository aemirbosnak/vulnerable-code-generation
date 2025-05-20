//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} TextLine;

typedef struct {
    TextLine *lines;
    int num_lines;
} Ebook;

Ebook *ebook_create(void) {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void ebook_destroy(Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_add_line(Ebook *ebook, const char *text) {
    TextLine *line = malloc(sizeof(TextLine));
    line->text = strdup(text);
    line->length = strlen(text);
    ebook->lines = realloc(ebook->lines, sizeof(TextLine) * (ebook->num_lines + 1));
    ebook->lines[ebook->num_lines] = *line;
    ebook->num_lines++;
}

void ebook_print(const Ebook *ebook) {
    for (int i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main(void) {
    Ebook *ebook = ebook_create();

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *trimmed_buffer = strdup(buffer);
        char *line = strtok(trimmed_buffer, "\n");
        while (line!= NULL) {
            ebook_add_line(ebook, line);
            line = strtok(NULL, "\n");
        }
        free(trimmed_buffer);
    }

    ebook_print(ebook);

    ebook_destroy(ebook);
    return 0;
}