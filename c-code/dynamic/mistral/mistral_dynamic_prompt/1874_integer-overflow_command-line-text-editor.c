#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define LINE_LENGTH 256

char lines[MAX_LINES][LINE_LENGTH];
int num_lines = 0;

void print_editor() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%d: %s\n", i + 1, lines[i]);
    }
}

void insert_line(int line, char* input) {
    if (line < 1 || line > num_lines + 1) {
        printf("Invalid line number.\n");
        return;
    }

    for (int i = num_lines; i > line; --i) {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[line - 1], input);
    num_lines++;
}

int main(int argc, char* argv[]) {
    char buffer[LINE_LENGTH];
    int line;

    printf("Simple Text Editor\n");
    while (1) {
        print_editor();
        printf("\nEnter command (load <line> <text> or exit): ");
        fgets(buffer, sizeof(buffer), stdin);

        char command[32];
        sscanf(buffer, "%s %d %*s", command, &line);

        if (strcmp(command, "load") == 0) {
            printf("Input text: ");
            fgets(buffer, sizeof(buffer), stdin);
            insert_line(line, buffer);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
