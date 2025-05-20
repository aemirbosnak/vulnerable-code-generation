#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

void edit_line(char *line, int line_num) {
    char buffer[MAX_LINE];
    printf("Line %d:\n", line_num);
    printf("%s\n", line);
    printf("Enter new line: ");
    fgets(buffer, MAX_LINE, stdin);
    strcpy(line, buffer);
}

int main() {
    char lines[10][MAX_LINE];
    int num_lines = 0;

    while (1) {
        printf("\nText Editor\n");
        printf("1. Edit a line\n2. Save and exit\n");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (num_lines == 0) {
                printf("No lines to edit.\n");
            } else {
                int line_num;
                printf("Enter line number to edit (1-%d): ", num_lines);
                scanf("%d", &line_num);
                if (line_num > num_lines || line_num < 1) {
                    printf("Invalid line number.\n");
                } else {
                    edit_line(lines[line_num - 1], line_num);
                }
            }
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    // Dereference failure vulnerability
    printf("Saving...\n");
    for (int i = 0; i < num_lines; ++i) {
        printf("%s", lines[i]); // Accessing uninitialized 'i'th element of lines[]
    }

    return 0;
}
