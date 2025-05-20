#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_CHARS 256

char lines[MAX_LINES][MAX_CHARS];
int num_lines = 0;

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%s\n", lines[i]);
    }
}

void add_line(char* line) {
    if (num_lines >= MAX_LINES) {
        printf("Error: Maximum number of lines reached.\n");
        return;
    }
    strcpy(lines[num_lines], line);
    ++num_lines;
}

int main() {
    char buffer[MAX_CHARS];
    char* token;
    int arg_count;
    char* args[MAX_LINES];

    while (1) {
        printf("> ");
        fgets(buffer, MAX_CHARS, stdin);
        token = strtok(buffer, " \n");
        arg_count = 0;
        while (token != NULL) {
            args[arg_count++] = token;
            token = strtok(NULL, " \n");
        }

        if (strcmp(args[0], "quit") == 0) {
            break;
        } else if (strcmp(args[0], "print") == 0) {
            print_lines();
        } else if (strcmp(args[0], "add") == 0) {
            if (arg_count < 2) {
                printf("Error: 'add' command requires an argument.\n");
            } else {
                add_line(args[1]);
            }
        } else {
            printf("Error: Unknown command.\n");
        }
    }

    return 0;
}
