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

void display_editor(Editor *editor) {
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
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    Editor editor;
    init_editor(&editor);

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(&editor, buffer);
    }

    fclose(file);

    display_editor(&editor);

    free_editor(&editor);

    // Integer overflow vulnerability
    int overflow_value = editor.line_count;
    overflow_value += 1000000000; // This will cause an overflow if line_count is large enough

    printf("Overflow value: %d\n", overflow_value);

    return 0;
}
