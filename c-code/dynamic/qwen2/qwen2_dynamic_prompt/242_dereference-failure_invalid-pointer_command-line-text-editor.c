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

void insert_text(TextEditor *editor, const char *text) {
    size_t new_length = editor->length + strlen(text);
    editor->content = realloc(editor->content, new_length + 1);
    if (editor->content == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(editor->content + editor->length, text);
    editor->length = new_length;
}

void print_editor(const TextEditor *editor) {
    printf("%s", editor->content);
}

int main(int argc, char *argv[]) {
    TextEditor editor;
    init_editor(&editor);

    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (file == NULL) {
            perror("Failed to open file");
            return 1;
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), file)) {
            insert_text(&editor, line);
        }

        fclose(file);
    } else {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_editor(&editor);

    free_editor(&editor);
    return 0;
}
