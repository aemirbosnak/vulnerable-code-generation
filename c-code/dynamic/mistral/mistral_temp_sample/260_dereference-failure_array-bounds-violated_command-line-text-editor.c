#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 1024
#define LINE_NUM 20

char lines[LINE_NUM][MAX_LINE];
int cursor_y = 0, cursor_x = 0;

void print_lines() {
    for (int i = 0; i < LINE_NUM; ++i) {
        if (lines[i][0] != '\0') {
            printf("%s\n", lines[i]);
        }
    }
}

void move_cursor(int dy, int dx) {
    cursor_y += dy;
    cursor_x += dx;

    if (cursor_y < 0) cursor_y = 0;
    if (cursor_y >= LINE_NUM) cursor_y = LINE_NUM - 1;
    if (cursor_x < 0) cursor_x = 0;

    char c = lines[cursor_y][cursor_x];
    printf("%c", (c != '\0' ? c : ' '));
}

void insert_char(char c) {
    lines[cursor_y][cursor_x] = c;
    ++cursor_x;
    if (cursor_x > MAX_LINE) {
        lines[cursor_y + 1][0] = '\0';
        cursor_y++;
        cursor_x = 1;
    }
}

int main() {
    char input[MAX_LINE];

    while (1) {
        print_lines();
        move_cursor(0, -1);

        fgets(input, MAX_LINE, stdin);
        if (strcmp(input, "\n") == 0) continue;

        if (strcmp(input, "q\n") == 0) break;

        strncpy(lines[cursor_y] + cursor_x, input, strlen(input));
        move_cursor(0, strlen(input));
    }

    return 0;
}
