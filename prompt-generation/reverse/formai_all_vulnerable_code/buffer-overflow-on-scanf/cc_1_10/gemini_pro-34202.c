//GEMINI-pro DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct {
    int x, y;
} Position;

typedef struct {
    Position pos;
    int score;
} Player;

typedef struct {
    Position pos;
    int value;
} Food;

void generate_food(Food *food, Player *player) {
    do {
        food->pos.x = rand() % SIZE;
        food->pos.y = rand() % SIZE;
    } while (food->pos.x == player->pos.x && food->pos.y == player->pos.y);
}

void draw_board(Player *player, Food *food) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == player->pos.y && j == player->pos.x)
                printf("P ");
            else if (i == food->pos.y && j == food->pos.x)
                printf("F ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void update_player(Player *player, int direction) {
    switch (direction) {
        case 'w':
            player->pos.y--;
            break;
        case 's':
            player->pos.y++;
            break;
        case 'a':
            player->pos.x--;
            break;
        case 'd':
            player->pos.x++;
            break;
    }

    if (player->pos.x < 0)
        player->pos.x = SIZE - 1;
    else if (player->pos.x >= SIZE)
        player->pos.x = 0;
    if (player->pos.y < 0)
        player->pos.y = SIZE - 1;
    else if (player->pos.y >= SIZE)
        player->pos.y = 0;
}

int main() {
    srand(time(NULL));

    Player player = { .pos = { .x = SIZE / 2, .y = SIZE / 2 }, .score = 0 };
    Food food;
    generate_food(&food, &player);

    char direction;
    while (1) {
        draw_board(&player, &food);
        printf("Score: %d\n", player.score);
        printf("Enter a direction (w/s/a/d): ");
        scanf(" %c", &direction);

        update_player(&player, direction);

        if (player.pos.x == food.pos.x && player.pos.y == food.pos.y) {
            player.score++;
            generate_food(&food, &player);
        }
    }

    return 0;
}