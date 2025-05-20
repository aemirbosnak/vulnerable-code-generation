#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_line(char *line) {
    char input[MAX_LINE_LENGTH];
    printf("Enter new line: ");
    fgets(input, sizeof(input), stdin);
    // Vulnerability: No bounds checking on sscanf
    sscanf(input, "%s", line);
}

int main() {
    char line[MAX_LINE_LENGTH] = "Initial content";
    printf("Current line: %s\n", line);

    while (1) {
        printf("Edit line? [y/n]: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n') break;

        edit_line(line);
        printf("Updated line: %s\n", line);
    }

    return 0;
}
