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

    printf("Welcome to the insecure text editor!\n");
    printf("Type 'exit' to quit.\n");

    while (1) {
        printf("> ");
        read = getline(&text, &len, stdin);
        if (read == -1) {
            break;
        }

        if (strncmp(text, "exit", 4) == 0) {
            break;
        }

        // Vulnerability: No bounds checking on text input
        printf("You typed: %s\n", text);
    }

    free(text);
}

int main(int argc, char *argv[]) {
    edit_text();
    return 0;
}
