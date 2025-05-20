#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

typedef struct {
    char *text;
    int length;
} Line;

void add_line(Line *lines, const char *line) {
    lines[lines->length].text = strdup(line);
    lines[lines->length].length = strlen(line);
    lines->length++;
}

void print_lines(Line *lines) {
    for (int i = 0; i < lines->length; i++) {
        printf("%s\n", lines[i].text);
    }
}

void free_lines(Line *lines) {
    for (int i = 0; i < lines->length; i++) {
        free(lines[i].text);
    }
}

int main() {
    Line lines = {NULL, 0};
    char buffer[256];
    int choice;

    while (1) {
        printf("1. Add line\n");
        printf("2. Print lines\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter line: ");
                fgets(buffer, sizeof(buffer), stdin);
                add_line(&lines, buffer);
                break;
            case 2:
                print_lines(&lines);
                break;
            case 3:
                free_lines(&lines);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
