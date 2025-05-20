#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

typedef struct {
    char *lines[MAX_LINES];
} TextEditor;

void init_editor(TextEditor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        editor->lines[i] = NULL;
    }
}

void add_line(TextEditor *editor, int line_number, const char *text) {
    if (line_number >= MAX_LINES || line_number < 0) return;
    editor->lines[line_number] = strdup(text);
}

void print_lines(TextEditor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        if (editor->lines[i]) {
            printf("%s\n", editor->lines[i]);
        }
    }
}

void free_editor(TextEditor *editor) {
    for (int i = 0; i < MAX_LINES; i++) {
        free(editor->lines[i]);
    }
}

int main() {
    TextEditor editor;
    init_editor(&editor);

    add_line(&editor, 0, "This is a test.");
    add_line(&editor, 1, "Another line.");

    print_lines(&editor);

    // Intentional invalid pointer dereference
    char *ptr = *(editor.lines + 2); // This will cause a segmentation fault
    printf("Invalid pointer: %s\n", ptr);

    free_editor(&editor);

    return 0;
}
