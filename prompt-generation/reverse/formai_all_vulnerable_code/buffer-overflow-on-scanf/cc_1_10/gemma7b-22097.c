//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 25

typedef struct Cell {
    int x, y;
    struct Cell* next;
} Cell;

Cell* createCell(int x, int y) {
    Cell* cell = malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->next = NULL;
    return cell;
}

void destroyCell(Cell* cell) {
    free(cell);
}

int main() {
    Cell* head = createCell(0, 0);
    head->next = createCell(1, 0);
    head->next->next = createCell(2, 0);

    int x = 0, y = 0;
    char cmd;

    printf("Enter 'w', 'a', 's', or 'd': ");
    scanf("%c", &cmd);

    switch (cmd) {
        case 'w':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 's':
            y--;
            break;
        case 'd':
            x++;
            break;
        default:
            printf("Invalid command.\n");
            break;
    }

    printf("New position: (%d, %d)\n", x, y);

    destroyCell(head);
    return 0;
}