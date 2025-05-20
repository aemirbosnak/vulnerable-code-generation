#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

void edit_text(char *lines[], int line_count) {
    char buffer[256];
    while (1) {
        printf("Enter line number to edit (or 'q' to quit): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (buffer[0] == 'q') break;
        int line_number = atoi(buffer);
        if (line_number < 1 || line_number > line_count) {
            printf("Invalid line number.\n");
            continue;
        }
        printf("Current line: %s", lines[line_number - 1]);
        printf("Enter new line: ");
        fgets(buffer, sizeof(buffer), stdin);
        snprintf(lines[line_number - 1], 256, "%s", buffer);
    }
}

int main() {
    char *lines[MAX_LINES];
    for (int i = 0; i < MAX_LINES; i++) {
        lines[i] = (char *)malloc(256 * sizeof(char));
    }

    // Simulate loading some initial lines
    snprintf(lines[0], 256, "This is line 1.\n");
    snprintf(lines[1], 256, "This is line 2.\n");

    int line_count = 2;

    edit_text(lines, line_count);

    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i]);
    }

    return 0;
}
