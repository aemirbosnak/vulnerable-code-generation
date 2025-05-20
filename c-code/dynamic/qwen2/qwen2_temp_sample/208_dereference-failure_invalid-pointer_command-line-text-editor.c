#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char *buffer[MAX_LINES];
    int line_count;
} Editor;

void init_editor(Editor *editor) {
    editor->line_count = 0;
}

void add_line(Editor *editor, const char *text) {
    if (editor->line_count >= MAX_LINES) return;
    editor->buffer[editor->line_count] = strdup(text);
    editor->line_count++;
}

void print_editor(Editor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->buffer[i]);
    }
}

void free_editor(Editor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->buffer[i]);
    }
}

int main(int argc, char *argv[]) {
    Editor editor;
    init_editor(&editor);

    // Simulate adding lines to the editor
    add_line(&editor, "This is a test.");
    add_line(&editor, "Another line.");

    // Dereference invalid pointer
    char *invalid_ptr = NULL;
    printf("%s\n", invalid_ptr); // This will cause a segmentation fault

    // Print editor content
    print_editor(&editor);

    // Free editor resources
    free_editor(&editor);

    return 0;
}
