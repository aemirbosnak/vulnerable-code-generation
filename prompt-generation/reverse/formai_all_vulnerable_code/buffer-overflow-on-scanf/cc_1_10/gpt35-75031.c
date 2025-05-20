//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Donald Knuth
#include <stdio.h>

#define ROWS 10
#define COLS 10

enum Direction { UP, DOWN, LEFT, RIGHT };

void printMap(char map[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

void moveInDirection(int *row, int *col, enum Direction direction) {
    switch (direction) {
        case UP:
            *row -= 1;
            break;
        case DOWN:
            *row += 1;
            break;
        case LEFT:
            *col -= 1;
            break;
        case RIGHT:
            *col += 1;
            break;
    }
}

int main() {
    char map[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '.', '#', '#', '.', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '#', '#', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int row = 1, col = 2;
    enum Direction direction = RIGHT;

    printf("Welcome to Procedural Space Adventure!\n\n");
    printf("You are an astronaut on a mission to explore a planet.\n");
    printf("Your spaceship has crash landed and you must find a way to return home.\n\n");
    printf("Legend:\n# - Wall\n. - Empty Space\nP - You\nE - Exit\n\n");
    map[row][col] = 'P';

    while (1) {
        printMap(map);
        printf("\nChoose direction to move: (u) up, (d) down, (l) left, (r) right\n");
        char input;
        scanf(" %c", &input);

        if (input == 'u') {
            direction = UP;
        } else if (input == 'd') {
            direction = DOWN;
        } else if (input == 'l') {
            direction = LEFT;
        } else if (input == 'r') {
            direction = RIGHT;
        } else {
            printf("Invalid input. Try again.\n");
            continue;
        }

        int newRow = row, newCol = col;
        moveInDirection(&newRow, &newCol, direction);

        if (!isValid(newRow, newCol) || map[newRow][newCol] == '#') {
            printf("You hit a wall. Try again.\n");
            continue;
        }

        map[row][col] = '.';
        row = newRow;
        col = newCol;
        map[row][col] = 'P';

        if (map[row][col] == 'E') {
            printf("Congratulations! You found the exit and returned home safely.\n");
            break;
        }
    }

    return 0;
}