#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_text() {
    char *text = NULL;
    size_t len = 0;
    ssize_t read;

    printf("Welcome to the Text Editor!\n");
    printf("Type 'exit' to save and quit.\n");

    while ((read = getline(&text, &len, stdin)) != -1) {
        if (text[0] == 'e' && text[1] == 'x' && text[2] == 'i' && text[3] == 't') {
            break;
        }
        printf("%s", text);
    }

    free(text);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("Usage: %s\n", argv[0]);
        return 1;
    }

    edit_text();

    return 0;
}
