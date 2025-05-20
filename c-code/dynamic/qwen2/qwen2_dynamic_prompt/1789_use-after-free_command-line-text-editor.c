#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

typedef struct {
    char *lines[MAX_LINES];
    int line_count;
} TextEditor;

void init_editor(TextEditor *editor) {
    editor->line_count = 0;
}

void add_line(TextEditor *editor, const char *line) {
    if (editor->line_count >= MAX_LINES) return;
    editor->lines[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_lines(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->lines[i]);
    }
}

void free_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->lines[i]);
    }
    editor->line_count = 0;
}

int main() {
    TextEditor editor;
    init_editor(&editor);

    add_line(&editor, "Hello, world!");
    add_line(&editor, "This is a test.");
    print_lines(&editor);

    free_editor(&editor);

    // Use-after-free vulnerability
    printf("%s\n", editor.lines[0]); // This will crash because editor.lines[0] was freed

    return 0;
}
