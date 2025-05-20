#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 1000

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

int main(int argc, char *argv[]) {
    Editor editor;
    init_editor(&editor);

    // Simulate an integer overflow by adding lines until it overflows
    for (int i = 0; i < MAX_LINES + 100; i++) {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "Line %d", i);
        add_line(&editor, buffer);
    }

    print_editor(&editor);

    free_editor(&editor);
    return 0;
}
