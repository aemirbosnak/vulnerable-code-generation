#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_LINES 256

typedef struct Line {
    char *content;
    struct Line *next;
} Line;

Line *head = NULL;

void add_line(char *line) {
    Line *new_line = (Line *)malloc(sizeof(Line));
    new_line->content = strdup(line);
    new_line->next = head;
    head = new_line;
}

void print_lines() {
    Line *current = head;
    while (current != NULL) {
        printf("%s\n", current->content);
        current = current->next;
    }
}

int main() {
    char buffer[BUFFER_SIZE];
    char *token;

    printf("Text Editor\n");

    while (1) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);
        token = strtok(buffer, "\n");

        if (strcmp(token, "exit") == 0) {
            break;
        } else if (strcmp(token, "save") == 0) {
            token = strtok(NULL, " \t");
            FILE *file = fopen(token, "w");
            Line *current = head;
            while (current != NULL) {
                fprintf(file, "%s", current->content);
                current = current->next;
            }
            fclose(file);
        } else {
            add_line(token);
        }
    }

    return 0;
}
