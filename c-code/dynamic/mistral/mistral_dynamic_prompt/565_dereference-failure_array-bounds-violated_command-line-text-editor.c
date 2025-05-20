#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 100
#define ARRAY_SIZE 10

void edit(char lines[][MAX_LINE]) {
    char input[MAX_LINE];
    char* cur_line = lines[0];
    int line_num = 0;

    for (;;) {
        printf("\nLine %d: %s\n", line_num + 1, cur_line);
        printf("> ");
        fgets(input, MAX_LINE, stdin);

        if (strncmp(input, "save", 4) == 0) {
            break;
        } else if (strncmp(input, "next", 4) == 0) {
            line_num++;
            line_num %= ARRAY_SIZE;
            cur_line = lines[line_num];
        } else if (strncmp(input, "prev", 4) == 0) {
            line_num--;
            if (line_num < 0)
                line_num += ARRAY_SIZE;
            cur_line = lines[line_num];
        } else {
            strcpy(cur_line + strlen(cur_line), input);
        }
    }
}

int main() {
    char* lines[ARRAY_SIZE] = {"Hello, world!", "I'm a text editor", "This is a dangerous example."};
    char temp[MAX_LINE];

    edit(lines);

    // Demonstrate the unsafe behavior by accessing beyond the allocated size.
    strcpy(temp, lines[2]);
    printf("\nOriginal: %s", lines[2]);
    printf("\nModified: %s", temp + strlen(temp) + 10); // Accessing beyond the end of the string

    return 0;
}
