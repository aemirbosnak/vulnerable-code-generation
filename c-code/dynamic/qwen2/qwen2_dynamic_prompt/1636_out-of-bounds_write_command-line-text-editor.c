#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_line(char *line, int index, char *new_char) {
    if (index >= MAX_LINE_LENGTH - 1) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    line[index] = new_char[0];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <index> <char>\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);
    char new_char[2] = {argv[2][0], '\0'};

    char line[MAX_LINE_LENGTH] = "Hello, World!\n";

    edit_line(line, index, new_char);

    printf("Modified line: %s\n", line);

    return 0;
}
