#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

typedef struct {
    char *text[MAX_LINES];
} Editor;

void init_editor(Editor *e) {
    for (int i = 0; i < MAX_LINES; i++) {
        e->text[i] = NULL;
    }
}

void add_line(Editor *e, int line, const char *str) {
    if (line >= MAX_LINES || line < 0) return;
    e->text[line] = strdup(str);
}

void print_editor(Editor *e) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (e->text[i]) {
            printf("%s\n", e->text[i]);
        } else {
            printf("\n");
        }
    }
}

void free_editor(Editor *e) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (e->text[i]) {
            free(e->text[i]);
        }
    }
}

int main() {
    Editor editor;
    init_editor(&editor);

    // Simulate adding lines to the editor
    add_line(&editor, 0, "This is line 1.");
    add_line(&editor, 1, "This is line 2.");
    add_line(&editor, 2, "This is line 3.");

    // Intentionally access an out-of-bounds index to cause a dereference failure
    add_line(&editor, 10, "This should cause a crash.");

    print_editor(&editor);

    free_editor(&editor);

    return 0;
}
