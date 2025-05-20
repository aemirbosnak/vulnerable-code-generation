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
} TextEditor;

void init_editor(TextEditor *editor) {
    editor->line_count = 0;
}

void add_line(TextEditor *editor, const char *line) {
    if (editor->line_count >= MAX_LINES) return;
    editor->text[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->text[i]);
    }
}

void free_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->text[i]);
    }
}

int main() {
    TextEditor editor;
    init_editor(&editor);

    add_line(&editor, "This is a test.");
    add_line(&editor, "Another line.");

    print_editor(&editor);

    // Dereference failure: accessing freed memory
    free_editor(&editor);
    printf("%s\n", editor.text[0]); // This will cause a segmentation fault

    return 0;
}
