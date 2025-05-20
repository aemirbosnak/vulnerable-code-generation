//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} Ebook;

Ebook *ebook_create() {
    Ebook *ebook = malloc(sizeof(Ebook));
    ebook->lines = NULL;
    ebook->num_lines = 0;
    return ebook;
}

void ebook_destroy(Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        free(ebook->lines[i].text);
    }
    free(ebook->lines);
    free(ebook);
}

void ebook_add_line(Ebook *ebook, char *text) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->length = strlen(text);
    ebook->lines = realloc(ebook->lines, sizeof(Line) * (ebook->num_lines + 1));
    ebook->lines[ebook->num_lines] = *line;
    ebook->num_lines++;
}

void ebook_print(Ebook *ebook) {
    int i;
    for (i = 0; i < ebook->num_lines; i++) {
        printf("%s\n", ebook->lines[i].text);
    }
}

int main() {
    Ebook *ebook = ebook_create();
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        char *line = strdup(buffer);
        char *token = strtok(line, " \n\r\t.,?!;:");
        while (token!= NULL) {
            ebook_add_line(ebook, token);
            token = strtok(NULL, " \n\r\t.,?!;:");
        }
        free(line);
    }
    ebook_print(ebook);
    ebook_destroy(ebook);
    return 0;
}