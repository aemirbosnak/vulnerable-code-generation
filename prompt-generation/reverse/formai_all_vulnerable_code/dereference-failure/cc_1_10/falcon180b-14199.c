//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
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
    int max_lines;
} Text;

void init_text(Text *t) {
    t->lines = NULL;
    t->num_lines = 0;
    t->max_lines = 0;
}

void add_line(Text *t, const char *s) {
    if (t->num_lines >= t->max_lines) {
        t->max_lines += 10;
        t->lines = realloc(t->lines, sizeof(Line *) * t->max_lines);
    }

    Line *l = malloc(sizeof(Line));
    l->text = strdup(s);
    l->length = strlen(s);

    t->lines[t->num_lines++] = l;
}

void print_text(const Text *t) {
    for (int i = 0; i < t->num_lines; i++) {
        printf("%s\n", t->lines[i]->text);
    }
}

void free_text(Text *t) {
    for (int i = 0; i < t->num_lines; i++) {
        free(t->lines[i]->text);
        free(t->lines[i]);
    }
    free(t->lines);
}

int main() {
    FILE *f;
    char filename[256];
    char line[MAX_LINE_LENGTH];
    Text text;

    init_text(&text);

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), f)!= NULL) {
        add_line(&text, line);
    }

    fclose(f);

    print_text(&text);

    free_text(&text);

    return 0;
}