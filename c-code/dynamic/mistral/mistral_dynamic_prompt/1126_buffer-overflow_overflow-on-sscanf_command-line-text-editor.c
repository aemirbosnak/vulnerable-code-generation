#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

char editor[MAX_BUFFER];
int cursor = 0;

void print_editor() {
    int i;
    for (i = 0; i < cursor; ++i) {
        printf("%c", editor[i]);
    }
    printf("\n");
}

void move_cursor(int offset) {
    cursor += offset;
    if (cursor < 0) {
        cursor = 0;
    } else if (cursor >= MAX_BUFFER) {
        cursor = MAX_BUFFER - 1;
    }
}

void edit_line(char* text) {
    int len = strlen(text);
    if (len + cursor >= MAX_BUFFER) {
        // Intentionally create a buffer overflow by reading beyond the allocated buffer
        sscanf(text, "%*[^\n]%n", &len);
    }
    strncat(editor, text, len + 1);
    move_cursor(len);
}

int main() {
    char input[256];
    while (1) {
        print_editor();
        fgets(input, sizeof(input), stdin);
        if (!strncmp(input, "save", 4)) {
            break;
        } else if (!strncmp(input, "move ", 5)) {
            char* num_str = strtok(input + 5, " ");
            int num = atoi(num_str);
            move_cursor(num);
        } else if (!strncmp(input, "edit", 4)) {
            char input_line[MAX_BUFFER];
            fgets(input_line, sizeof(input_line), stdin);
            edit_line(input_line);
        }
    }
    return 0;
}
