#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 80

typedef struct {
    char *lines[MAX_LINES];
    int line_count;
} TextEditor;

void init_editor(TextEditor *editor) {
    editor->line_count = 0;
    for (int i = 0; i < MAX_LINES; i++) {
        editor->lines[i] = NULL;
    }
}

void add_line(TextEditor *editor, const char *line) {
    if (editor->line_count >= MAX_LINES) {
        printf("Error: Reached maximum number of lines.\n");
        return;
    }
    editor->lines[editor->line_count++] = strdup(line);
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

    while (1) {
        printf("Command (a to add line, p to print, q to quit): ");
        char command;
        scanf(" %c", &command);

        if (command == 'q') {
            break;
        } else if (command == 'a') {
            char line[MAX_LINE_LENGTH + 1];
            printf("Enter line: ");
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = '\0'; // Remove newline character
            add_line(&editor, line);
        } else if (command == 'p') {
            print_lines(&editor);
        } else {
            printf("Invalid command.\n");
        }
    }

    free_editor(&editor);
    return 0;
}
