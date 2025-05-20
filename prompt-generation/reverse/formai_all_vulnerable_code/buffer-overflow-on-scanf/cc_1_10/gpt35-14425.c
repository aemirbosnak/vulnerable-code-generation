//FormAI DATASET v1.0 Category: Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 7
#define MAX_MOVES 20

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    UP=1,
    DOWN=2,
    LEFT=3,
    RIGHT=4
} Direction;

int grid[GRID_SIZE][GRID_SIZE];

// initialize the grid with random values between -5 and 5
void init_grid() {
    srand(time(NULL));
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = rand() % 11 - 5;
        }
    }
}

// display the grid
void display_grid() {
    printf("\n");
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }
}

// move the current position on the grid in the specified direction
void move(Direction direction, Position *p) {
    switch (direction) {
        case UP:
            if (p->y > 0) p->y--;
            break;
        case DOWN:
            if (p->y < GRID_SIZE-1) p->y++;
            break;
        case LEFT:
            if (p->x > 0) p->x--;
            break;
        case RIGHT:
            if (p->x < GRID_SIZE-1) p->x++;
            break;
        default:
            break;
    }
}

int main() {
    Position current_position = {0, 0};
    int total_moves = 0;
    int total_score = 0;

    init_grid();
    display_grid();

    while (total_moves < MAX_MOVES) {
        char choice;
        printf("\nCurrent position is (%d, %d). Choose a direction to move (u/d/l/r): ", current_position.x, current_position.y);
        scanf("%c", &choice); // read user input
        getchar(); // consume newline character

        Direction direction;
        switch (choice) {
            case 'u':
                direction = UP;
                break;
            case 'd':
                direction = DOWN;
                break;
            case 'l':
                direction = LEFT;
                break;
            case 'r':
                direction = RIGHT;
                break;
            default:
                direction = UP; // default direction (just for testing purposes)
                break;
        }

        move(direction, &current_position);
        total_moves++;
        total_score += grid[current_position.y][current_position.x]; // add the score of the current position to the total score

        printf("\nMoved to (%d, %d). Scored %d points. Total score is %d.\n", current_position.x, current_position.y, grid[current_position.y][current_position.x], total_score);

        display_grid();
    }

    printf("\nGame over. Total score: %d.\n", total_score);

    return 0;
}