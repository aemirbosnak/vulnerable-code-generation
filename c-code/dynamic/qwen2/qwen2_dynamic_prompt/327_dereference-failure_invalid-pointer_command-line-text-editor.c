#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void edit_text(char *text[], int *line_count) {
    char buffer[256];
    while (1) {
        printf("Line %d: ", *line_count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '\n') break;
        text[*line_count] = strdup(buffer);
        (*line_count)++;
    }
}

void display_text(char *text[], int line_count) {
    for (int i = 0; i < line_count; i++) {
        printf("%s", text[i]);
    }
}

int main() {
    char *lines[MAX_LINES];
    int line_count = 0;

    printf("Welcome to the Text Editor!\n");
    printf("Enter lines of text. Type an empty line to finish.\n");

    edit_text(lines, &line_count);

    printf("\nYour text:\n");
    display_text(lines, line_count);

    // Intentional dereference failure
    free(lines[line_count]); // This will cause a segmentation fault because line_count is out of bounds

    return 0;
}
