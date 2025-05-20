#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[10];
char editor[500];
char *cursor = editor;

void print_editor() {
    printf("\n");
    for (int i = 0; i < 500; ++i) {
        if (i == (cursor - editor)) printf("\033[1;31m%c\033[0m", editor[i]);
        else printf("%c", editor[i]);
    }
}

void move_cursor(int offset) {
    cursor += offset;
}

void write_char(char c) {
    *cursor++ = c;
    editor[500] = '\0';
    print_editor();
}

int main() {
    char cmd[50];

    for (;;) {
        printf("> ");
        fgets(cmd, 50, stdin);
        sscanf(cmd, "%s", buf);

        if (!strcmp(buf, "new")) {
            memset(editor, 0, 500);
            cursor = editor;
        } else if (!strcmp(buf, "save")) {
            FILE *file = fopen("output.txt", "w");
            if (file) {
                fputs(editor, file);
                fclose(file);
            }
        } else if (!strcmp(buf, "exit")) {
            break;
        } else if (strlen(buf) + strlen(editor) + 1 > 500) {
            // Intentionally unchecked buffer overflow
            strcat(editor, buf);
        } else {
            strcat(editor, buf);
            move_cursor(strlen(editor));
        }

        print_editor();
    }

    return 0;
}
