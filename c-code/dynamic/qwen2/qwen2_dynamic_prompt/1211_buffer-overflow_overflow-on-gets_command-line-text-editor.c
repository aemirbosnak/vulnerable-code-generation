#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *text) {
    char line[MAX_LINE_LENGTH];
    int index = 0;

    while (index < MAX_LINE_LENGTH - 1) {
        printf("Line %d: ", index + 1);
        if (fgets(line, sizeof(line), stdin)) {
            size_t len = strlen(line);
            if (len > 0 && line[len - 1] == '\n') {
                line[len - 1] = '\0';
            }
            strcat(text, line);
            strcat(text, "\n");
            index++;
        } else {
            break;
        }
    }
}

int main() {
    char *text = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    if (!text) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    strcpy(text, "");

    printf("Welcome to the Text Editor!\n");
    printf("Enter your text. Type 'exit' to finish.\n");

    edit_text(text);

    printf("\nYour edited text:\n%s", text);

    free(text);
    return EXIT_SUCCESS;
}
