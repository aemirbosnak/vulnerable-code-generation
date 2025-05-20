//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *input;
    int length;
    int errors;
} line_t;

void print_line(line_t *line) {
    printf("%s", line->input);
    for (int i = 0; i < line->length; i++) {
        printf("_");
    }
    printf("\n");
}

int get_typing_speed(line_t *line) {
    char c;
    int errors = 0;
    while ((c = getchar()) != EOF) {
        if (c != line->input[line->length]) {
            errors++;
        }
        line->length++;
    }
    return errors;
}

int main() {
    int nlines;
    printf("Enter the number of lines to generate: ");
    scanf("%d", &nlines);

    line_t *lines = malloc(nlines * sizeof(line_t));
    for (int i = 0; i < nlines; i++) {
        lines[i].input = malloc(MAX_LINE_LENGTH * sizeof(char));
        lines[i].length = 0;
        lines[i].errors = 0;
    }

    for (int i = 0; i < nlines; i++) {
        print_line(&lines[i]);
    }

    for (int i = 0; i < nlines; i++) {
        lines[i].errors = get_typing_speed(&lines[i]);
    }

    for (int i = 0; i < nlines; i++) {
        printf("Line %d: %d errors\n", i + 1, lines[i].errors);
    }

    for (int i = 0; i < nlines; i++) {
        free(lines[i].input);
    }
    free(lines);

    return 0;
}