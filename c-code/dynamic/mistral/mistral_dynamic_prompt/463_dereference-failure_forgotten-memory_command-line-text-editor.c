#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t len;
} TextEditor;

TextEditor create() {
    TextEditor editor = { NULL, 0 };
    return editor;
}

void print(TextEditor editor) {
    for (size_t i = 0; i < editor.len; ++i) {
        putchar(editor.data[i]);
    }
    printf("\n");
}

void append(TextEditor *editor, const char *str) {
    char *new_data = (char *)realloc(editor->data, editor->len + strlen(str) + 1);
    if (!new_data) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    memcpy(new_data + editor->len, str, strlen(str) + 1);
    editor->len += strlen(str);
    editor->data = new_data;
}

void edit(TextEditor *editor, const char *command) {
    if (!strcmp(command, "print")) {
        print(*editor);
    } else if (!strcmp(command, "append")) {
        char input[100];
        printf("Enter string to append: ");
        fgets(input, sizeof(input), stdin);
        append(editor, input);
    }
}

int main() {
    TextEditor editor = create();
    char line[100];

    while (1) {
        printf("Text editor> ");
        fgets(line, sizeof(line), stdin);
        edit(&editor, strtok(line, " "));
    }

    free(editor.data);
    return 0;
}
