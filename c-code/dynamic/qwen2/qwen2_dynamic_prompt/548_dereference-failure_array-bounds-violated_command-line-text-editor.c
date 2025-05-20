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
        printf("Error: Maximum number of lines reached.\n");
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

void free_editor(TextEditor *editor) {
    for (int i = 0; i < editor->line_count; i++) {
        free(editor->lines[i]);
    }
}

int main(int argc, char *argv[]) {
    TextEditor editor;
    init_editor(&editor);

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        add_line(&editor, line);
    }

    fclose(file);

    // Intentional dereference failure: accessing beyond array bounds
    printf("Line at index 100: %s\n", editor.lines[100]);

    print_lines(&editor);
    free_editor(&editor);

    return 0;
}
