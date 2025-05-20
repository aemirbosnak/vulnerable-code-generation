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

void init_editor(Editor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        editor->text[i] = NULL;
    }
}

void add_line(Editor *editor, int line_num, const char *line) {
    if (line_num >= MAX_LINES || line_num < 0) return;
    editor->text[line_num] = strdup(line);
}

void print_editor(Editor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (editor->text[i]) {
            printf("%s\n", editor->text[i]);
        }
    }
}

void free_editor(Editor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (editor->text[i]) {
            free(editor->text[i]);
        }
    }
}

int main() {
    Editor editor;
    init_editor(&editor);

    // Simulate adding lines to the editor
    add_line(&editor, 0, "This is a test.");
    add_line(&editor, 1, "Another line.");
    add_line(&editor, 2, "A third line.");

    // Print the contents of the editor
    print_editor(&editor);

    // Intentionally cause an array bounds violation
    add_line(&editor, 10, "This should cause a crash.");

    // Free allocated memory
    free_editor(&editor);

    return 0;
}
