#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char editor[MAX_LINE];
int cur_pos = 0;

void clear_screen() {
    printf("\033[2J\033[H");
}

void move_cursor(int offset) {
    if (cur_pos + offset < 0 || cur_pos + offset > MAX_LINE - 1) {
        printf("Invalid cursor position.\n");
        return;
    }
    cur_pos += offset;
}

void insert_at_cursor(const char *str) {
    int str_len = strlen(str);
    if (str_len + cur_pos > MAX_LINE - 1) {
        printf("Buffer overflow detected.\n");
        return;
    }

    memmove(editor + cur_pos + str_len, editor + cur_pos, MAX_LINE - cur_pos);
    strcpy(editor + cur_pos, str);
    cur_pos += str_len;
}

void print_editor() {
    clear_screen();
    int i;
    for (i = 0; i < cur_pos; ++i) {
        printf("%c", editor[i]);
    }
    for (; i < MAX_LINE; ++i) {
        printf(" ");
    }
    printf("\n");
}

int main() {
    char command[10];
    int num;

    while (1) {
        print_editor();
        scanf("%s", command);

        if (!strcmp(command, "insert")) {
            char input[MAX_LINE];
            printf("Enter the string to insert: ");
            scanf("%[^\n]", input);
            sscanf(input, "%d", &num);
            move_cursor(-num);
            insert_at_cursor(input);
            move_cursor(num);
        }
        // Additional editor commands...
    }

    return 0;
}
