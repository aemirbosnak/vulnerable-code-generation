//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Point;

int main() {
    int num_rows, num_columns, r, c;
    Point player, snake, apple;
    Point *snake_head, *snake_tail;
    Point next_move;
    int score = 0;

    srand(time(NULL)); // Seed random number generator
    snake_head = &snake; // Set snake head position to the snake's position
    snake_tail = &snake; // Set snake tail position to the snake's position

    printf("Welcome to Snake! Press any key to start.\n");
    getchar();

    printf("Size of the board: ");
    scanf("%d %d", &num_rows, &num_columns);
    if (num_rows * num_columns > 0) {
        snake_head->x = (rand() % num_columns) * 2;
        snake_head->y = (rand() % num_rows) * 2;
        snake_tail->x = snake_head->x;
        snake_tail->y = snake_head->y;

        apple.x = (rand() % num_columns) * 2;
        apple.y = (rand() % num_rows) * 2;

        printf("Snake head position: (%d, %d)\n", snake_head->x, snake_head->y);
        printf("Apple position: (%d, %d)\n", apple.x, apple.y);
    } else {
        printf("Invalid size of the board. Exiting...\n");
        return 1;
    }

    while (1) {
        printf("Move %d\n", score);
        printf("Current score: %d\n", score);

        printf("Enter a direction: (up, down, left, right)\n");
        scanf("%d", &c);
        if (c < 0 || c > 3) {
            printf("Invalid direction. Try again.\n");
            continue;
        }

        switch (c) {
            case 0:
                next_move.x -= 1;
                next_move.y += 0;
                break;
            case 1:
                next_move.x += 1;
                next_move.y += 0;
                break;
            case 2:
                next_move.x += 0;
                next_move.y -= 1;
                break;
            case 3:
                next_move.x -= 0;
                next_move.y -= 1;
                break;
            default:
                printf("Invalid direction. Try again.\n");
                continue;
        }

        if (next_move.x < 0 || next_move.x >= num_columns || next_move.y < 0 || next_move.y >= num_rows) {
            printf("Out of bounds. Try again.\n");
            continue;
        }

        if (next_move.x == apple.x && next_move.y == apple.y) {
            score++;
            printf("You ate an apple! Score: %d\n", score);
            snake_tail->x = snake_head->x;
            snake_tail->y = snake_head->y;
            snake_head->x = next_move.x;
            snake_head->y = next_move.y;
            printf("Snake head position: (%d, %d)\n", snake_head->x, snake_head->y);
        } else if (next_move.x == snake_head->x && next_move.y == snake_head->y) {
            printf("You hit yourself. Game over.\n");
            return 1;
        } else {
            if (snake_tail->x == next_move.x && snake_tail->y == next_move.y) {
                printf("You hit the tail. Game over.\n");
                return 1;
            }

            snake_tail->x = snake_head->x;
            snake_tail->y = snake_head->y;
            snake_head->x = next_move.x;
            snake_head->y = next_move.y;
            printf("Snake head position: (%d, %d)\n", snake_head->x, snake_head->y);
        }
    }
}