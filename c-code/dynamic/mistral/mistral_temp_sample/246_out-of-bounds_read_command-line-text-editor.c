#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE 256

char lines[10][MAX_LINE];
int num_lines = 0;
int current_line = 0;

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%s\n", lines[i]);
    }
}

void input_line() {
    char input[MAX_LINE];
    fgets(input, sizeof(input), stdin);
    strcpy(lines[num_lines++], input);
    current_line = num_lines - 1;
}

void next_line() {
    if (current_line < num_lines - 1) {
        current_line++;
    }
}

void prev_line() {
    if (current_line > 0) {
        current_line--;
    }
}

int main() {
    char cmd[5];

    while (1) {
        printf("> ");
        scanf("%s", cmd);

        if (strcmp(cmd, "save") == 0) {
            print_lines();
            break;
        } else if (strcmp(cmd, "quit") == 0) {
            break;
        } else if (strcmp(cmd, "write") == 0) {
            input_line();
        } else if (strcmp(cmd, "next") == 0) {
            next_line();
        } else if (strcmp(cmd, "prev") == 0) {
            prev_line();
        } else if (strcmp(cmd, "read") == 0) {
            int pos = atoi(cmd + 5);
            if (pos >= 0 && pos < num_lines) {
                printf("%s\n", lines[pos]);
            }
        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
