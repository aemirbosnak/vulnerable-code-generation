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
    printf("Enter your text (type 'exit' to save and quit):\n");

    while ((read = getline(&text, &len, stdin)) != -1) {
        if (strncmp(text, "exit", 4) == 0) {
            break;
        }
        printf("Text: %s", text);
    }

    free(text);
}

int main(int argc, char *argv[]) {
    edit_text();
    return 0;
}
