#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char buffer[MAX_LINE];

void edit_line(int line) {
    printf("Line %d:\n%s\n", line, buffer);
    printf("Enter new text (up to %d characters): ", MAX_LINE);
    scanf("%s", buffer);
}

void save_file() {
    printf("Saving file...\n");
    // Save the modified buffer to a file
}

int main() {
    int lines = 3;
    int current_line = 1;

    printf("Simple Text Editor\n");

    while (1) {
        if (current_line > lines) {
            printf("Last line.\n");
            break;
        }

        edit_line(current_line);

        if (strcmp(buffer, "") != 0) {
            strcpy(buffer + strlen(buffer), "\0"); // Intentionally creating a buffer overflow
            current_line++;
        } else {
            current_line--;
        }
    }

    save_file();
    printf("Exiting...\n");

    return 0;
}
