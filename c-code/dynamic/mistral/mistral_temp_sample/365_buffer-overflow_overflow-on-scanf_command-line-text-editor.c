#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024

char buffer[MAX_LINE];
int cursor = 0;

void display_buffer() {
    int i;
    for (i = 0; i < cursor; ++i)
        putchar(buffer[i]);
}

void append_char(char c) {
    buffer[cursor++] = c;
    buffer[cursor] = '\0';
}

void move_cursor(int offset) {
    if (cursor + offset < 0 || cursor + offset > MAX_LINE) {
        printf("Error: Invalid cursor movement\n");
        return;
    }
    cursor += offset;
}

void read_line() {
    char input[MAX_LINE];
    fgets(input, sizeof(input), stdin);
    strcpy(buffer + cursor, input);
    cursor += strlen(input);
}

int main() {
    char command;
    while (1) {
        display_buffer();
        printf(" > ");
        command = getchar();
        int size = scanf("%c", &command);
        if (size == EOF) break;

        switch (command) {
            case 'a':
                append_char(' ');
                break;
            case 'w':
                read_line();
                break;
            case 'l':
                move_cursor(-1);
                break;
            case 'h':
                move_cursor(-10);
                break;
            case 'f':
                move_cursor(10);
                break;
            case 'q':
                return 0;
            default:
                printf("Unknown command\n");
        }
    }
    return 0;
}
