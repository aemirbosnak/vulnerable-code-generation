//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    struct Line *next;
} Line;

Line *head = NULL;
int num_lines = 0;

void add_line(char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->line = line;
    new_line->next = NULL;

    if (head == NULL) {
        head = new_line;
    } else {
        Line *curr_line = head;
        while (curr_line->next!= NULL) {
            curr_line = curr_line->next;
        }
        curr_line->next = new_line;
    }

    num_lines++;
}

void print_lines() {
    Line *curr_line = head;
    while (curr_line!= NULL) {
        printf("%s\n", curr_line->line);
        curr_line = curr_line->next;
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        add_line(line);
        if (num_lines >= MAX_NUM_LINES) {
            printf("Maximum number of lines reached. Exiting...\n");
            exit(1);
        }
    }

    printf("Number of lines: %d\n", num_lines);
    print_lines();

    return 0;
}