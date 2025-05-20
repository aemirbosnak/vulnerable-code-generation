#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 128

void edit_text(char *text) {
    char buffer[MAX_LINE_LENGTH];
    printf("Enter your text: ");
    gets(buffer); // Vulnerable to buffer overflow
    strcat(text, buffer);
}

int main() {
    char *text = malloc(MAX_LINE_LENGTH);
    if (text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(text, "Initial text: ");
    edit_text(text);

    printf("Edited text: %s\n", text);

    free(text);
    return 0;
}
