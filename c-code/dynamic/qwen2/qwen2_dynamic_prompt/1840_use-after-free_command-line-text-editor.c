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
    if (editor->line_count >= MAX_LINES) {
        printf("Error: Editor is full.\n");
        return;
    }
    editor->lines[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_lines(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        printf("%s\n", editor->lines[i]);
    }
}

void delete_line(TextEditor *editor, int index) {
    if (index < 0 || index >= editor->line_count) {
        printf("Error: Invalid line number.\n");
        return;
    }
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
    init_editor(&editor);

    add_line(&editor, "Hello, world!");
    add_line(&editor, "This is a test.");
    add_line(&editor, "Use after free vulnerability.");

    print_lines(&editor);

    delete_line(&editor, 1);

    // Use after free vulnerability
    printf("%s\n", editor.lines[1]); // This will cause undefined behavior

    free_editor(&editor);

    return 0;
}
