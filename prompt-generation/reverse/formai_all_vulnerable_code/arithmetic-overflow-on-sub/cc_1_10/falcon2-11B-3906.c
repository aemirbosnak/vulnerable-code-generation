//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>

struct maze {
    int *data;
    int size;
};

void printMaze(struct maze *m) {
    int i, j;
    for (i = 0; i < m->size; i++) {
        for (j = 0; j < m->size; j++) {
            if (m->data[i * m->size + j] == 1)
                printf("*");
            else if (m->data[i * m->size + j] == 0)
                printf("O");
            else
                printf(" ");
        }
        printf("\n");
    }
}

void setCell(struct maze *m, int x, int y, int value) {
    if (x >= 0 && x < m->size && y >= 0 && y < m->size) {
        m->data[x * m->size + y] = value;
    }
}

void solveMaze(struct maze *m) {
    if (m->data[0 * m->size + 0] == 1) {
        printf("Start (%d, %d)\n", 0, 0);
        return;
    } else if (m->data[m->size - 1 * m->size + m->size - 1] == 1) {
        printf("End (%d, %d)\n", m->size - 1, m->size - 1);
        return;
    }

    int i, j;
    for (i = 0; i < m->size; i++) {
        for (j = 0; j < m->size; j++) {
            if (m->data[i * m->size + j] == 0) {
                solveMaze(m);
            }
        }
    }
}

int main() {
    int mSize;
    printf("Enter the size of the maze: ");
    scanf("%d", &mSize);
    struct maze *m = (struct maze*)malloc(sizeof(struct maze));
    m->size = mSize;
    m->data = (int*)malloc(mSize * mSize * sizeof(int));
    for (int i = 0; i < mSize; i++) {
        for (int j = 0; j < mSize; j++) {
            m->data[i * mSize + j] = 0;
        }
    }
    printf("Maze:\n");
    printMaze(m);

    printf("\n1. View the maze\n");
    printf("2. Set a cell as blocked or open\n");
    printf("3. Solve the maze\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice!= 0) {
        switch (choice) {
            case 1:
                printMaze(m);
                break;
            case 2:
                printf("Enter the coordinates of the cell to set: ");
                int x, y;
                scanf("%d%d", &x, &y);
                printf("Enter 1 to set as blocked, 0 to set as open: ");
                int value;
                scanf("%d", &value);
                setCell(m, x, y, value);
                printf("\n");
                printMaze(m);
                break;
            case 3:
                solveMaze(m);
                printf("\nSolved maze:\n");
                printMaze(m);
                break;
            default:
                printf("Invalid choice!\n");
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("I am done!\n");
    return 0;
}