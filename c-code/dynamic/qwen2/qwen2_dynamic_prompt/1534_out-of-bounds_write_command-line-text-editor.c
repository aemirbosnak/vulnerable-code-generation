#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_line(char *line, int index, char *text) {
    if (index >= MAX_LINE_LENGTH - 1) {
        printf("Error: Index out of bounds.\n");
        return;
    }
    line[index] = text[0];
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <index> <text>\n", argv[0]);
        return 1;
    }

    int index = atoi(argv[1]);
    char *text = argv[2];

    char line[MAX_LINE_LENGTH];
    strcpy(line, "Initial content");

    edit_line(line, index, text);

    printf("Modified line: %s\n", line);

    return 0;
}
