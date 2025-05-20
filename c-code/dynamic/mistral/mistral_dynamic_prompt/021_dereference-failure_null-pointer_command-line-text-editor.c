#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Editor {
    char* content;
    size_t size;
} Editor;

Editor* createEditor() {
    Editor* editor = malloc(sizeof(Editor));
    editor->content = NULL;
    editor->size = 0;
    return editor;
}

void resizeEditor(Editor* editor, size_t new_size) {
    char* temp = realloc(editor->content, new_size);
    if (!temp) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    editor->content = temp;
}

void appendEditor(Editor* editor, const char* text) {
    size_t new_size = editor->size + strlen(text) + 1;
    resizeEditor(editor, new_size);
    strcat(editor->content, text);
}

void printEditor(const Editor* editor) {
    printf("%s", editor->content);
}

void editLine(Editor* editor, size_t line, const char* text) {
    if (line >= editor->size) {
        fprintf(stderr, "Line out of bounds!\n");
        return;
    }

    char* start = editor->content + line;
    strcpy(start, text);
}

int main() {
    Editor* editor = createEditor();

    appendEditor(editor, "Hello, World!\n");
    appendEditor(editor, "This is a simple text editor.\n");
    appendEditor(editor, "Let's edit a line.\n");

    printEditor(editor);

    editLine(editor, 1, "Modified line.");
    printEditor(editor);

    editor->content[editor->size - 15] = '\0'; // Dereference failure example
    printf("%s\n", editor->content);

    return 0;
}
