#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void edit_line(char **buffer, int *cursor) {
    char line[MAX_LINE];

    printf("Line %d: %s\n", *cursor, (*buffer));
    printf("Enter a new line (or '.' to save and quit): ");
    fgets(line, MAX_LINE, stdin);

    free(*buffer);
    *buffer = (char *) malloc((strlen(line) + 1) * sizeof(char));
    strcpy(*buffer, line);

    (*cursor)++;
}

int main() {
    char *buffer = (char *) malloc(1 * sizeof(char));
    int cursor = 0;

    while (1) {
        if (cursor >= 10) {
            printf("Too many lines!\n");
            break;
        }

        edit_line(&buffer, &cursor);
    }

    printf("Exiting the editor...\n");
    free(buffer);

    return 0;
}
