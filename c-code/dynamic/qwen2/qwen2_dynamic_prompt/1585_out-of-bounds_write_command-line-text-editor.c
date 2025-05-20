#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

char buffer[MAX_LINES][LINE_LENGTH];

void print_lines(int start, int end) {
    for (int i = start; i <= end && i < MAX_LINES; i++) {
        printf("%s", buffer[i]);
    }
}

void insert_line(int line_number, const char *text) {
    if (line_number >= MAX_LINES) return;
    strcpy(buffer[line_number], text);
}

void delete_line(int line_number) {
    if (line_number >= MAX_LINES) return;
    strcpy(buffer[line_number], "");
}

int main() {
    int current_line = 0;

    while (1) {
        printf("Line %d> ", current_line + 1);
        char input[256];
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q') break;
        if (input[0] == 'p') {
            print_lines(0, MAX_LINES - 1);
        } else if (input[0] == 'i') {
            insert_line(current_line, input + 2);
            current_line++;
        } else if (input[0] == 'd') {
            delete_line(current_line);
        } else if (input[0] == 'm' && input[1] == 'o' && input[2] == 'v' && input[3] == 'e') {
            int new_line;
            sscanf(input + 4, "%d", &new_line);
            if (new_line >= 0 && new_line < MAX_LINES) {
                current_line = new_line;
            }
        }
    }

    return 0;
}
