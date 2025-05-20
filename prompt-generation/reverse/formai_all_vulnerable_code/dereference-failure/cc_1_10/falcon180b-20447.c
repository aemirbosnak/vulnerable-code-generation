//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

Line lines[MAX_NUM_LINES];
int num_lines = 0;

void add_line(char *line) {
    if (num_lines >= MAX_NUM_LINES) {
        printf("Error: Too many lines.\n");
        exit(1);
    }
    lines[num_lines].line = malloc(strlen(line) + 1);
    strcpy(lines[num_lines].line, line);
    lines[num_lines].length = strlen(line);
    num_lines++;
}

void remove_line(int index) {
    if (index >= num_lines || index < 0) {
        printf("Error: Invalid line index.\n");
        exit(1);
    }
    free(lines[index].line);
    for (int i = index; i < num_lines - 1; i++) {
        lines[i] = lines[i + 1];
    }
    num_lines--;
}

void print_lines() {
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", i + 1, lines[i].line);
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (input[0] == '#') {
            // Comment line, ignore
        } else if (input[0] == '@') {
            // Add line
            char *line = input + 1;
            while (isspace(*line)) {
                line++;
            }
            add_line(line);
        } else if (input[0] == '!') {
            // Remove line
            char *line = input + 1;
            while (isspace(*line)) {
                line++;
            }
            int index = atoi(line) - 1;
            remove_line(index);
        } else {
            // Invalid input, ignore
        }
    }
    print_lines();
    return 0;
}