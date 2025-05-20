#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 256

char buffer[MAX_LINE];
int cursor = 0;

void edit_line() {
    printf("Line %d: %s\n", __LINE__, buffer);
    printf("> ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        printf("\nExiting...\n");
        exit(0);
    }
}

int main() {
    char command[10];

    while (1) {
        edit_line();

        sscanf(buffer, "%s", command);
        if (strcmp(command, "save") == 0) {
            printf("Saving file...\n");
            // Save the buffer to a file, not shown here for brevity
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(command, "insert") == 0) {
            char input[MAX_LINE];
            printf("Enter text to insert: ");
            edit_line();
            strncat(buffer, input, MAX_LINE); // Intentionally overflowing the buffer
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
