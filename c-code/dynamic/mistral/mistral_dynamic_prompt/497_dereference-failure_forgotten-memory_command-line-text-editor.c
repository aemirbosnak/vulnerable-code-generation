#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void edit(char *text) {
    char line[BUFFER_SIZE];
    char *cursor = text;

    while (1) {
        printf("%s\n$ ", text);
        scanf("%s", line);

        if (strcmp(line, "save") == 0) {
            break;
        } else if (strcmp(line, "quit") == 0) {
            free(cursor);
            return;
        } else {
            strcat(text, line);
            strcat(text, " ");
        }

        cursor += strlen(line) + 1;
    }
}

int main() {
    char *text = malloc(BUFFER_SIZE);
    memset(text, 0, BUFFER_SIZE);

    edit(text);

    return 0;
}
