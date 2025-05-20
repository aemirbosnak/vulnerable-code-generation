#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct Line {
    char *data;
    struct Line *next;
} Line;

Line *head = NULL;

void append_line(char *line) {
    Line *new_line = (Line *) malloc(sizeof(Line));
    new_line->data = strdup(line);
    new_line->next = NULL;

    if (!head) {
        head = new_line;
        return;
    }

    Line *cursor = head;
    while (cursor->next) {
        cursor = cursor->next;
    }
    cursor->next = new_line;
}

void print_lines() {
    Line *cursor = head;
    while (cursor) {
        printf("%s\n", cursor->data);
        cursor = cursor->next;
    }
}

void read_line() {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, stdin);
    append_line(line);
}

int main() {
    char command[10];
    while (1) {
        printf("> ");
        fgets(command, 10, stdin);
        if (strcmp(command, "quit\n") == 0) {
            break;
        }
        if (strcmp(command, "print\n") == 0) {
            print_lines();
        } else {
            read_line();
        }
    }
    return 0;
}
