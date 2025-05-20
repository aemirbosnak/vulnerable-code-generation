#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_CHARS 256

char lines[MAX_LINES][MAX_CHARS];
int num_lines = 0;

void clear_screen() {
    system("clear");
}

void print_lines() {
    int i;
    for (i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

void write_line(int line_num, char* line) {
    if (line_num > 0 && line_num <= num_lines + 1) {
        strcpy(lines[line_num - 1], line);
        num_lines = (num_lines >= line_num) ? num_lines : line_num;
    }
}

int main() {
    char command[MAX_CHARS], arg1[MAX_CHARS], arg2[MAX_CHARS];
    int line_num;

    while (1) {
        clear_screen();
        print_lines();
        printf("\n> ");
        fgets(command, MAX_CHARS, stdin);

        if (strcmp(command, "EXIT\n") == 0) {
            break;
        }

        sscanf(command, "%s %s %d", arg1, arg2, &line_num);

        if (strcmp(arg1, "WRITE") == 0) {
            fgets(arg2, MAX_CHARS, stdin);
            write_line(line_num, arg2);
        } else if (strcmp(arg1, "APPEND") == 0) {
            fgets(arg2, MAX_CHARS, stdin);
            strcat(lines[line_num - 1], arg2);
        } else {
            printf("Invalid command: %s\n", arg1);
        }
    }

    return 0;
}
