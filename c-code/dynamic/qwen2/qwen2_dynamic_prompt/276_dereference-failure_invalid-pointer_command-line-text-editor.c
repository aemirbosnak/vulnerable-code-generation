#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *content;
    size_t length;
} TextEditor;

void init_editor(TextEditor *editor) {
    editor->content = NULL;
    editor->length = 0;
}

void free_editor(TextEditor *editor) {
    if (editor->content != NULL) {
        free(editor->content);
        editor->content = NULL;
        editor->length = 0;
    }
}

void insert_text(TextEditor *editor, const char *text, size_t pos) {
    size_t new_length = editor->length + strlen(text);
    char *new_content = realloc(editor->content, new_length + 1);
    if (new_content == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    editor->content = new_content;
    memmove(editor->content + pos + strlen(text), editor->content + pos, editor->length - pos + 1);
    memcpy(editor->content + pos, text, strlen(text));
    editor->length = new_length;
}

void print_editor(const TextEditor *editor) {
    printf("%s", editor->content);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    TextEditor editor;
    init_editor(&editor);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        insert_text(&editor, line, editor.length);
    }

    fclose(file);

    print_editor(&editor);

    free_editor(&editor);

    return 0;
}
