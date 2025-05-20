#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 10

void edit_text(char *text) {
    char line[MAX_LINE_LENGTH];
    while (1) {
        printf("Enter a line (or 'exit' to quit): ");
        if (fgets(line, sizeof(line), stdin) == NULL) {
            break;
        }
        if (line[0] == '\n') {
            continue;
        }
        if (strncmp(line, "exit", 4) == 0) {
            break;
        }
        if (strlen(text) + strlen(line) >= MAX_LINE_LENGTH - 1) {
            printf("Error: Text exceeds maximum length.\n");
            continue;
        }
        strcat(text, line);
    }
}

int main() {
    char text[MAX_LINE_LENGTH] = "";
    printf("Welcome to the simple text editor!\n");
    edit_text(text);
    printf("Final text:\n%s\n", text);
    return 0;
}
