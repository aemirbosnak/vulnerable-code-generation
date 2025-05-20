#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char **lines;
    int num_lines;
} TextEditor;

void init_editor(TextEditor *editor) {
    editor->lines = malloc(MAX_LINES * sizeof(char *));
    if (editor->lines == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    editor->num_lines = 0;
}

void insert_line(TextEditor *editor, const char *line) {
    if (editor->num_lines >= MAX_LINES) {
        fprintf(stderr, "Maximum number of lines reached\n");
        return;
    }
    editor->lines[editor->num_lines] = strdup(line);
    if (editor->lines[editor->num_lines] == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    editor->num_lines++;
}

void print_editor(TextEditor *editor) {
    for (int i = 0; i < editor->num_lines; i++) {
        printf("%s\n", editor->lines[i]);
    }
}

void free_editor(TextEditor *editor) {
    for (int i = 0; i < editor->num_lines; i++) {
        free(editor->lines[i]);
    }
    free(editor->lines);
}

int main(int argc, char *argv[]) {
    TextEditor editor;
    init_editor(&editor);

    for (int i = 1; i < argc; i++) {
        insert_line(&editor, argv[i]);
    }

    print_editor(&editor);

    free_editor(&editor);

    // Deliberate dereference failure: accessing out-of-bounds array element
    printf("%s\n", editor.lines[editor.num_lines]);

    return 0;
}
