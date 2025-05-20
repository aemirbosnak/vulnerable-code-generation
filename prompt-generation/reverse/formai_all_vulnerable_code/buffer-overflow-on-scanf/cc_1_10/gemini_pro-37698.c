//GEMINI-pro DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake {
    int head_x;
    int head_y;
    struct Snake *next;
};

struct Food {
    int x;
    int y;
};

void init_snake(struct Snake **snake) {
    struct Snake *new_snake = malloc(sizeof(struct Snake));
    new_snake->head_x = WIDTH / 2;
    new_snake->head_y = HEIGHT / 2;
    new_snake->next = NULL;
    *snake = new_snake;
}

void free_snake(struct Snake *snake) {
    struct Snake *current_snake = snake;
    while (current_snake != NULL) {
        struct Snake *next_snake = current_snake->next;
        free(current_snake);
        current_snake = next_snake;
    }
}

void init_food(struct Food *food) {
    srand(time(NULL));
    food->x = rand() % WIDTH;
    food->y = rand() % HEIGHT;
}

void draw_snake(struct Snake *snake) {
    struct Snake *current_snake = snake;
    while (current_snake != NULL) {
        printf("* ");
        current_snake = current_snake->next;
    }
    printf("\n");
}

void draw_food(struct Food *food) {
    printf("$ ");
}

void move_snake(struct Snake **snake, enum Direction direction) {
    struct Snake *new_snake = malloc(sizeof(struct Snake));
    new_snake->next = *snake;
    switch (direction) {
        case UP:
            new_snake->head_x = (*snake)->head_x;
            new_snake->head_y = (*snake)->head_y - 1;
            break;
        case DOWN:
            new_snake->head_x = (*snake)->head_x;
            new_snake->head_y = (*snake)->head_y + 1;
            break;
        case LEFT:
            new_snake->head_x = (*snake)->head_x - 1;
            new_snake->head_y = (*snake)->head_y;
            break;
        case RIGHT:
            new_snake->head_x = (*snake)->head_x + 1;
            new_snake->head_y = (*snake)->head_y;
            break;
    }
    *snake = new_snake;
}

int main() {
    struct Snake *snake = NULL;
    struct Food food;
    enum Direction direction = RIGHT;

    init_snake(&snake);
    init_food(&food);

    while (1) {
        draw_snake(snake);
        draw_food(&food);

        if (snake->head_x == food.x && snake->head_y == food.y) {
            init_food(&food);
        } else {
            struct Snake *current_snake = snake->next;
            while (current_snake != NULL) {
                if (snake->head_x == current_snake->head_x && snake->head_y == current_snake->head_y) {
                    printf("Game over!\n");
                    free_snake(snake);
                    return 0;
                }
                current_snake = current_snake->next;
            }
            move_snake(&snake, direction);
            free_snake(snake->next);
        }

        char input;
        scanf(" %c", &input);
        switch (input) {
            case 'w':
                direction = UP;
                break;
            case 's':
                direction = DOWN;
                break;
            case 'a':
                direction = LEFT;
                break;
            case 'd':
                direction = RIGHT;
                break;
            case 'q':
                free_snake(snake);
                return 0;
        }
        system("clear");
    }

    return 0;
}