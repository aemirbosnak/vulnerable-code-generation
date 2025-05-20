#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10
#define MAX_LINES 100
#define MAX_CHAR_PER_LINE 256

char lines[MAX_LINES][MAX_CHAR_PER_LINE];
int num_lines = 0;

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%s\n", lines[i]);
    }
}

void add_line(char* line) {
    if (num_lines == MAX_LINES) {
        printf("Error: Too many lines.\n");
        return;
    }
    strcpy(lines[num_lines++], line);
}

int main(int argc, char* argv[]) {
    char buffer[BUFFER_SIZE];
    char* current_line = NULL;
    int current_line_index = -1;

    while (1) {
        if (current_line_index >= 0) {
            print_lines();
            printf("%d: ", current_line_index + 1);
        } else {
            printf("(new line): ");
        }

        fgets(buffer, BUFFER_SIZE, stdin);

        if (current_line_index >= 0) {
            strcpy(lines[current_line_index], buffer);
        } else {
            current_line = malloc(strlen(buffer) + 1);
            strcpy(current_line, buffer);
            add_line(current_line);
            current_line_index = num_lines - 1;
        }

        if (strchr(buffer, 'q') != NULL) {
            break;
        }
    }

    return 0;
}
