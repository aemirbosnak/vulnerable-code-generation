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
    if (editor->line_count >= MAX_LINES) return;
    editor->lines[editor->line_count] = strdup(line);
    editor->line_count++;
}

void print_editor(TextEditor *editor) {
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

int main(int argc, char *argv[]) {
    TextEditor editor;
    init_editor(&editor);

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Error opening file");
            return EXIT_FAILURE;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), file)) {
            add_line(&editor, line);
        }

        fclose(file);
    } else {
        printf("Usage: %s [filename]\n", argv[0]);
        return EXIT_FAILURE;
    }

    print_editor(&editor);

    // Intentional dereference failure (forgotten memory)
    char *last_line = editor.lines[editor.line_count - 1];
    printf("Last line: %s\n", last_line); // This will cause undefined behavior

    free_editor(&editor);
    return EXIT_SUCCESS;
}
