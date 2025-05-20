//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct Line {
    char **data;
    int length;
    struct Line *next;
} Line;

Line *createLine(int length) {
    Line *line = malloc(sizeof(Line));
    line->data = malloc(sizeof(char *) * length);
    line->length = length;
    line->next = NULL;
    return line;
}

void addLine(Line *line, char **data, int length) {
    line->data[line->length++] = data;
    if (line->length >= MAX_LINES) {
        line = createLine(length);
        line->next = line->next ? line->next : NULL;
        line = line->next;
    }
    line->data[line->length - 1] = NULL;
}

int main() {
    Line *head = createLine(0);
    char **data = malloc(sizeof(char *) * 10);
    data[0] = "This is a line";
    data[1] = "It has a lot of text";
    data[2] = "And it is very long";
    addLine(head, data, 3);

    data = malloc(sizeof(char *) * 5);
    data[0] = "This is another line";
    data[1] = "It is shorter";
    data[2] = "And it has less text";
    addLine(head, data, 3);

    for (Line *current = head; current; current = current->next) {
        for (int i = 0; current->data[i] != NULL; i++) {
            printf("%s\n", current->data[i]);
        }
    }

    return 0;
}