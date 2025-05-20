//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 100000

typedef struct {
    char *line;
    struct line_node *next;
} line_node_t;

line_node_t *head = NULL;
line_node_t *tail = NULL;

int num_lines = 0;

void add_line(char *line) {
    line_node_t *new_node = (line_node_t *)malloc(sizeof(line_node_t));
    new_node->line = strdup(line);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        tail->next = new_node;
    }

    tail = new_node;
    num_lines++;
}

void print_lines() {
    line_node_t *curr_node = head;

    while (curr_node!= NULL) {
        printf("%s\n", curr_node->line);
        curr_node = curr_node->next;
    }
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];

    file = fopen("my_love_letter.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
    }

    fclose(file);

    print_lines();

    return 0;
}