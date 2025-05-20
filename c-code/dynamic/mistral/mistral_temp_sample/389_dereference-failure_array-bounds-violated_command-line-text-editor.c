#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define LINES 10

char lines[LINES][MAX_LINE];
int curr_line = 0;

void print_lines() {
    for (int i = 0; i < curr_line; i++) {
        printf("%s\n", lines[i]);
    }
}

void append_line() {
    char* input = (char*)malloc(MAX_LINE * sizeof(char));
    printf("Enter a line (or type 'exit' to quit): ");
    fgets(input, MAX_LINE, stdin);

    if (strcmp(input, "exit\n") == 0) {
        exit(0);
    }

    strcpy(lines[curr_line], input);
    curr_line++;
}

int main() {
    char command[5];

    while (1) {
        print_lines();
        printf("> ");
        fgets(command, 5, stdin);

        if (strcmp(command, "save\n") == 0) {
            printf("Saving...\n");
        } else if (strcmp(command, "quit\n") == 0) {
            printf("Exiting...\n");
            break;
        } else if (strcmp(command, "load\n") == 0) {
            printf("Loading...\n");
        } else if (strcmp(command, "append\n") == 0) {
            append_line();
        } else {
            // Buffer overflow vulnerability intentional
            strcpy(lines[curr_line], command);
            curr_line++;
        }
    }

    return 0;
}
