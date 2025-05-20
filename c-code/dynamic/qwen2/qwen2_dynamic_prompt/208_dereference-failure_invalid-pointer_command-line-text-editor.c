#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char *text[MAX_LINES];
    int line_count;
} Editor;

void init_editor(Editor *editor) {
    editor->line_count = 0;
}

void add_line(Editor *editor, const char *line) {
    if (editor->line_count >= MAX_LINES) {
        printf("Editor is full!\n");
        return;
    }
    editor->text[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_editor(Editor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->text[i]);
    }
}

void free_editor(Editor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->text[i]);
    }
}

int main() {
    Editor editor;
    init_editor(&editor);

    add_line(&editor, "This is a test.");
    add_line(&editor, "Another line.");

    // Intentional dereference failure: accessing freed memory
    free_editor(&editor);
    printf("%s\n", editor.text[0]); // Dereferencing freed memory

    return 0;
}
