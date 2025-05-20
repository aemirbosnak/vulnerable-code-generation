#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

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

void display_editor(TextEditor *editor) {
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

    while (1) {
        printf("Text Editor> ");
        char input[MAX_LINE_LENGTH];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "display") == 0) {
            display_editor(&editor);
        } else {
            add_line(&editor, input);
        }
    }

    free_editor(&editor);
    return 0;
}
