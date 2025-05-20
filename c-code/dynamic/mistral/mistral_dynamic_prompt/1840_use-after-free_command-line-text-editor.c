#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

typedef struct Line {
    char data[MAX_LINE];
    struct Line *next;
} Line;

Line *head = NULL;

void read_line(Line **list) {
    char line[MAX_LINE];
    if (fgets(line, sizeof(line), stdin) == NULL) {
        *list = NULL;
        return;
    }
    Line *new_line = (Line *)malloc(sizeof(Line));
    strcpy(new_line->data, line);
    new_line->next = *list;
    *list = new_line;
}

void free_list(Line *list) {
    Line *current, *next;
    current = list;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print_list(Line *list) {
    Line *current = list;
    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }
}

int main() {
    Line *current, *prev;
    head = NULL;

    printf("Text Editor\n");
    while (1) {
        read_line(&head);
        current = head;
        prev = NULL;

        if (head != NULL && strcmp(head->data, "save\n") == 0) {
            break;
        }

        if (head != NULL && strcmp(head->data, "quit\n") == 0) {
            free_list(head);
            return 0;
        }

        if (prev != NULL) {
            prev->next = NULL;
            free(current);
        } else {
            head = NULL;
        }

        prev = current;
    }

    print_list(head);
    printf("\n");

    return 0;
}
