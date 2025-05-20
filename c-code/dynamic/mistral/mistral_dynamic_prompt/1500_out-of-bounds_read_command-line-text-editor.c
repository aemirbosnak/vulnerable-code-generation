#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256

void edit_line(int line) {
    char buffer[MAX_BUFFER];
    printf("Line %d:\n", line);
    fgets(buffer, MAX_BUFFER, stdin);

    // Out of bounds read vulnerability
    char *line_content = malloc(line * MAX_BUFFER);
    strcpy(line_content, buffer);
    printf("Line content: %s\n", line_content[line * MAX_BUFFER]);

    free(line_content);
}

void print_menu() {
    printf("\nText Editor Menu:\n");
    printf("1. Edit Line\n");
    printf("2. Save and Exit\n");
    printf("3. Exit\n");
}

int main() {
    int selection;
    int lines = 0;
    char *lines_buffer = NULL;

    while (1) {
        print_menu();
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                if (lines > 0) {
                    printf("Enter the line number: ");
                    scanf("%d", &lines);
                    if (lines <= lines)
                        edit_line(lines);
                    else
                        printf("Invalid line number.\n");
                } else
                    edit_line(lines);
                break;

            case 2:
                // Save the data to a file (not shown for brevity)
                printf("Saving...\n");
                exit(0);
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}
