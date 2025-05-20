//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 20

typedef struct Cell {
    int x;
    int y;
    struct Cell* next;
} Cell;

void initialize(Cell** head) {
    *head = NULL;
}

void insert(Cell** head, int x, int y) {
    Cell* newNode = malloc(sizeof(Cell));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void move(Cell** head, int dx, int dy) {
    Cell* current = *head;

    while (current) {
        current->x += dx;
        current->y += dy;
        current = current->next;
    }
}

int main() {
    Cell* head = NULL;
    initialize(&head);

    insert(head, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 3, 0);

    move(head, 1, 1);

    for (Cell* current = head; current; current = current->next) {
        printf("(%d, %d)\n", current->x, current->y);
    }

    return 0;
}