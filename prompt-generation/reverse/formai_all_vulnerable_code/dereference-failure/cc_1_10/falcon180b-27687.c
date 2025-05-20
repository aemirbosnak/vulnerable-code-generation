//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    Line **lines;
    int num_lines;
} Document;

Document *create_document() {
    Document *doc = malloc(sizeof(Document));
    doc->lines = NULL;
    doc->num_lines = 0;
    return doc;
}

void add_line(Document *doc, char *text) {
    Line *line = malloc(sizeof(Line));
    line->text = strdup(text);
    line->length = strlen(text);
    doc->lines = realloc(doc->lines, sizeof(Line *) * ++doc->num_lines);
    doc->lines[doc->num_lines - 1] = line;
}

void print_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        printf("%s\n", doc->lines[i]->text);
    }
}

void free_document(Document *doc) {
    for (int i = 0; i < doc->num_lines; i++) {
        free(doc->lines[i]->text);
        free(doc->lines[i]);
    }
    free(doc->lines);
    free(doc);
}

int main() {
    Document *doc = create_document();
    char input_buffer[MAX_LINE_LENGTH];

    while (fgets(input_buffer, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(doc, input_buffer);
    }

    print_document(doc);

    free_document(doc);

    return 0;
}