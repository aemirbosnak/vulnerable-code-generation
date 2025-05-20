//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int spaceshipX, spaceshipY;

void initialize(int array[][COLS]) {
    // Initialize all cells to contain 0
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = 0;
        }
    }

    // Place spaceship at random position
    srand(time(NULL));
    spaceshipX = rand() % ROWS;
    spaceshipY = rand() % COLS;
    array[spaceshipX][spaceshipY] = 1;
}

void display(int array[][COLS]) {
    printf("\n");

    // Print column numbers
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Print rows
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);

        for (int j = 0; j < COLS; j++) {
            if (array[i][j] == 1) {
                printf("S ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int move(int array[][COLS]) {
    char direction;
    int newX = spaceshipX;
    int newY = spaceshipY;

    printf("\nWhich direction do you want to move in? (up, down, left, right): ");
    scanf(" %c", &direction);

    // Update newX and newY based on direction
    switch (direction) {
        case 'u':
            newX--;
            break;
        case 'd':
            newX++;
            break;
        case 'l':
            newY--;
            break;
        case 'r':
            newY++;
            break;
        default:
            printf("Invalid direction. Please try again.\n");
            return 0;
    }

    // Check if new position is within bounds
    if (newX < 0 || newX >= ROWS || newY < 0 || newY >= COLS) {
        printf("Oops, you hit a wall!\n");
        return 0;
    }

    // Check if landed on spaceship
    if (array[newX][newY] == 1) {
        printf("\nHooray! You found the spaceship and successfully completed your mission!\n");
        return 1;
    }

    // Update spaceship position
    array[spaceshipX][spaceshipY] = 0;
    spaceshipX = newX;
    spaceshipY = newY;
    array[spaceshipX][spaceshipY] = 1;

    return 0;
}

int main() {
    int board[ROWS][COLS];
    int foundSpaceship = 0;

    initialize(board);
    display(board);

    while (!foundSpaceship) {
        foundSpaceship = move(board);
        display(board);
    }

    return 0;
}