#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
int cursor = 0;

void move_cursor(int direction) {
    if (direction == -1 && cursor > 0)
        cursor--;
    else if (direction == 1 && cursor < MAX_LINE - 1)
        cursor++;
}

void write_char(char c) {
    if (cursor < MAX_LINE - 1)
        buffer[cursor++] = c;
}

void read_line() {
    int i = 0;
    char ch;

    while ((ch = getchar()) != EOF && i < MAX_LINE - 1) {
        buffer[i] = ch;
        i++;
    }

    buffer[i] = '\0';
    cursor = i;
}

void print_buffer() {
    int i;
    for (i = 0; i < cursor; i++)
        printf("%c", buffer[i]);

    printf("\n");
}

int main() {
    char command[10];
    int arg;

    while (1) {
        print_buffer();
        printf("> ");
        scanf("%s %d", command, &arg);

        if (!strcmp(command, "save")) {
            FILE *file = fopen("editor.txt", "w");
            fprintf(file, "%s", buffer);
            fclose(file);
        } else if (!strcmp(command, "quit")) {
            break;
        } else if (!strcmp(command, "move") && arg >= -MAX_LINE && arg <= MAX_LINE) {
            move_cursor(arg);
        } else if (!strcmp(command, "write") && arg < MAX_LINE) {
            write_char(arg);
        } else if (!strcmp(command, "read")) {
            read_line();
        }
    }

    return 0;
}
