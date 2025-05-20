//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_ROWS 20
#define NUM_COLS 40

struct point {
    int x;
    int y;
};

struct snake {
    struct point *body;
    int length;
    char direction;
};

void init_snake(struct snake *snake) {
    snake->length = 3;
    snake->body = malloc(sizeof(struct point) * snake->length);
    snake->body[0].x = NUM_ROWS / 2;
    snake->body[0].y = NUM_COLS / 2;
    snake->body[1].x = NUM_ROWS / 2;
    snake->body[1].y = NUM_COLS / 2 - 1;
    snake->body[2].x = NUM_ROWS / 2;
    snake->body[2].y = NUM_COLS / 2 - 2;
    snake->direction = 'r';
}

void free_snake(struct snake *snake) {
    free(snake->body);
}

void print_snake(struct snake *snake) {
    for (int i = 0; i < snake->length; i++) {
        printf("(%d, %d)\n", snake->body[i].x, snake->body[i].y);
    }
}

void move_snake(struct snake *snake) {
    struct point new_head;
    switch (snake->direction) {
        case 'r':
            new_head.x = snake->body[0].x;
            new_head.y = snake->body[0].y + 1;
            break;
        case 'l':
            new_head.x = snake->body[0].x;
            new_head.y = snake->body[0].y - 1;
            break;
        case 'u':
            new_head.x = snake->body[0].x - 1;
            new_head.y = snake->body[0].y;
            break;
        case 'd':
            new_head.x = snake->body[0].x + 1;
            new_head.y = snake->body[0].y;
            break;
    }

    for (int i = snake->length - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
    }

    snake->body[0] = new_head;
}

int main() {
    struct snake snake;
    init_snake(&snake);

    char input;
    while (1) {
        scanf("%c", &input);
        switch (input) {
            case 'w':
                snake.direction = 'u';
                break;
            case 's':
                snake.direction = 'd';
                break;
            case 'a':
                snake.direction = 'l';
                break;
            case 'd':
                snake.direction = 'r';
                break;
            case 'q':
                free_snake(&snake);
                exit(0);
        }

        move_snake(&snake);
        print_snake(&snake);
    }

    return 0;
}