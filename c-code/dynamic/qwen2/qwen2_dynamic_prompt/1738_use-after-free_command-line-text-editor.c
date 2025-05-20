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

void add_line(TextEditor *editor, const char *line) {
    if (editor->line_count >= MAX_LINES) return;
    editor->lines[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->lines[i]);
    }
}

void delete_line(TextEditor *editor, int index) {
    if (index < 0 || index >= editor->line_count) return;
    free(editor->lines[index]);
    for (int i = index; i < editor->line_count - 1; i++) {
        editor->lines[i] = editor->lines[i + 1];
    }
    editor->line_count--;
}

void free_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->lines[i]);
    }
    editor->line_count = 0;
}

int main() {
    TextEditor editor;
    memset(&editor, 0, sizeof(editor));

    add_line(&editor, "Hello");
    add_line(&editor, "World");

    print_editor(&editor);

    delete_line(&editor, 0);

    // Use-after-free vulnerability
    printf("%s\n", editor.lines[0]); // This will access freed memory

    free_editor(&editor);

    return 0;
}
