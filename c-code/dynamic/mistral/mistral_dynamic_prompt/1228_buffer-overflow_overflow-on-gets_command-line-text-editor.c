#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_SIZE 100

char buffer[MAX_SIZE];
int cursor = 0;

void draw_screen() {
    system("clear");
    printf("\033[%d;1H", cursor);
    printf("%s", buffer);
}

void read_line() {
    printf("\033[1;1H");
    printf("> ");
    fgets(buffer, MAX_SIZE, stdin);
}

void move_cursor(int offset) {
    cursor += offset;
    if (cursor >= MAX_SIZE) cursor -= MAX_SIZE;
    if (cursor < 0) cursor += MAX_SIZE;
}

int main() {
    int i;

    draw_screen();

    while (1) {
        read_line();
        for (i = 0; i < strlen(buffer); ++i) {
            buffer[cursor + i] = buffer[i];
        }
        buffer[cursor + strlen(buffer)] = '\0';
        memcpy(buffer, buffer + cursor, strlen(buffer) + 1);
        cursor = 0;
        draw_screen();
    }

    return 0;
}
