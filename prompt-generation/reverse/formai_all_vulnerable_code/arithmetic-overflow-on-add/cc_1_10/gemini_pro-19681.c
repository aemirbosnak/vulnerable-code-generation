//GEMINI-pro DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 25

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int length;
    Point* body;
    Direction direction;
} Snake;

typedef struct {
    int x;
    int y;
} Fruit;

Snake snake;
Fruit fruit;

void initGame();
void updateGame();
void drawGame();
void checkCollisions();
void moveSnake();
void placeFruit();
void resetGame();

int main() {
    initGame();

    while (1) {
        updateGame();
        drawGame();
        checkCollisions();
        moveSnake();
        placeFruit();
        resetGame();
    }

    return 0;
}

void initGame() {
    snake.length = 5;
    snake.body = malloc(sizeof(Point) * snake.length);
    snake.direction = RIGHT;

    fruit.x = rand() % SCREEN_WIDTH;
    fruit.y = rand() % SCREEN_HEIGHT;
}

void updateGame() {
    // Update the snake's position.
    moveSnake();

    // Check for collisions.
    checkCollisions();

    // Place a new fruit if the snake has eaten the current one.
    if (snake.body[0].x == fruit.x && snake.body[0].y == fruit.y) {
        placeFruit();
    }
}

void drawGame() {
    // Clear the screen.
    system("cls");

    // Draw the snake.
    for (int i = 0; i < snake.length; i++) {
        printf("o");
    }

    // Draw the fruit.
    printf("@");
}

void checkCollisions() {
    // Check if the snake has hit itself.
    for (int i = 1; i < snake.length; i++) {
        if (snake.body[0].x == snake.body[i].x && snake.body[0].y == snake.body[i].y) {
            resetGame();
        }
    }

    // Check if the snake has hit the wall.
    if (snake.body[0].x < 0 || snake.body[0].x >= SCREEN_WIDTH ||
        snake.body[0].y < 0 || snake.body[0].y >= SCREEN_HEIGHT) {
        resetGame();
    }
}

void moveSnake() {
    // Move the snake's head in the current direction.
    switch (snake.direction) {
        case UP:
            snake.body[0].y--;
            break;
        case DOWN:
            snake.body[0].y++;
            break;
        case LEFT:
            snake.body[0].x--;
            break;
        case RIGHT:
            snake.body[0].x++;
            break;
    }

    // Move the rest of the snake's body.
    for (int i = snake.length - 1; i > 0; i--) {
        snake.body[i].x = snake.body[i - 1].x;
        snake.body[i].y = snake.body[i - 1].y;
    }
}

void placeFruit() {
    fruit.x = rand() % SCREEN_WIDTH;
    fruit.y = rand() % SCREEN_HEIGHT;
}

void resetGame() {
    // Reset the snake's position.
    snake.length = 5;
    snake.direction = RIGHT;
    for (int i = 0; i < snake.length; i++) {
        snake.body[i].x = i;
        snake.body[i].y = 0;
    }

    // Place a new fruit.
    placeFruit();
}