#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
int cursor = 0;

void edit_line() {
    printf("\nLine %d: %s\n", __LINE__, buffer);
    char input[MAX_LINE];
    printf("> ");
    fgets(input, sizeof(input), stdin);

    if (strchr(input, '\n')) {
        strcpy(buffer + cursor, input);
        cursor += strlen(input);
    } else {
        strcat(buffer, input);
        cursor += strlen(input);
    }
}

void move_cursor(int steps) {
    cursor += steps;
    if (cursor >= MAX_LINE)
        cursor = 0;
    else if (cursor < 0)
        cursor = MAX_LINE - 1;
}

void print_line() {
    printf("\nLine %d: %*.*s%*.*s\n", __LINE__, cursor - strlen(buffer) + 1, cursor, "", MAX_LINE, cursor, buffer);
}

int main() {
    edit_line();
    int command;

    while (1) {
        printf("\nCommands:\n1. Edit\n2. Move cursor left\n3. Move cursor right\n4. Print line\n5. Exit\n> ");
        scanf("%d", &command);

        switch (command) {
            case 1:
                edit_line();
                break;
            case 2:
                move_cursor(-1);
                print_line();
                break;
            case 3:
                move_cursor(1);
                print_line();
                break;
            case 4:
                print_line();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}
