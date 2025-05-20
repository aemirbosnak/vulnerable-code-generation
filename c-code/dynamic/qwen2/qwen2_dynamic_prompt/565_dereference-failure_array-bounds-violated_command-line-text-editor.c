#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 10

void edit_text(char *text[], int line_count) {
    char buffer[256];
    while (1) {
        printf("Line %d: ", line_count + 1);
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == '\n') break;
        text[line_count++] = strdup(buffer);
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

    printf("Enter text. Type an empty line to finish.\n");
    edit_text(lines, line_count);

    printf("\nText entered:\n");
    display_text(lines, line_count);

    // Intentional dereference failure
    free(lines[10]); // This will cause a segmentation fault because lines[10] is out of bounds

    return 0;
}
