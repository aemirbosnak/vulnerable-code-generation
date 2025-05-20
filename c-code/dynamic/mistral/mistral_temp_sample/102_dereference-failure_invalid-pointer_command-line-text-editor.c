#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void edit_line(char *line, int line_num) {
    char buffer[MAX_LINE];
    printf("Line %d:\n", line_num);
    fgets(buffer, MAX_LINE, stdin);
    strcpy(line, buffer);
}

void print_lines() {
    char line[MAX_LINE];
    int i = 1;
    while (fgets(line, MAX_LINE, stdin) != NULL) {
        printf("Line %d: %s", i++, line);
    }
}

int main() {
    char **lines = (char *)malloc(10 * sizeof(char *));
    int num_lines = 0;

    char input[MAX_LINE];
    while (1) {
        printf("\n1. Edit line\n2. Print lines\n3. Exit\n> ");
        fgets(input, MAX_LINE, stdin);

        int choice = atoi(input);
        if (choice == 1) {
            if (num_lines >= 10) {
                printf("Too many lines.\n");
                continue;
            }
            lines[num_lines] = (char *)malloc(MAX_LINE * sizeof(char));
            edit_line(lines[num_lines], num_lines + 1);
            num_lines++;
        } else if (choice == 2) {
            print_lines();
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
