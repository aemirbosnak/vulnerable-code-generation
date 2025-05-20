//GEMINI-pro DATASET v1.0 Category: Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FIELD_WIDTH 10
#define FIELD_HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int direction; // 0: up, 1: right, 2: down, 3: left
} Player;

void initField(int field[][FIELD_HEIGHT]) {
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            field[x][y] = 0;
        }
    }
}

void printField(int field[][FIELD_HEIGHT]) {
    for (int y = 0; y < FIELD_HEIGHT; y++) {
        for (int x = 0; x < FIELD_WIDTH; x++) {
            printf("%d ", field[x][y]);
        }
        printf("\n");
    }
}

void movePlayer(Player *player, int field[][FIELD_HEIGHT]) {
    switch (player->direction) {
    case 0: // up
        if (player->position.y > 0) {
            player->position.y--;
        }
        break;
    case 1: // right
        if (player->position.x < FIELD_WIDTH - 1) {
            player->position.x++;
        }
        break;
    case 2: // down
        if (player->position.y < FIELD_HEIGHT - 1) {
            player->position.y++;
        }
        break;
    case 3: // left
        if (player->position.x > 0) {
            player->position.x--;
        }
        break;
    }
}

void placeTreasure(int field[][FIELD_HEIGHT]) {
    srand(time(NULL));

    int x = rand() % FIELD_WIDTH;
    int y = rand() % FIELD_HEIGHT;

    field[x][y] = 1;
}

int main() {
    int field[FIELD_WIDTH][FIELD_HEIGHT];
    Player player = {
        .position = {
            .x = 0,
            .y = 0,
        },
        .direction = 0,
    };

    initField(field);
    placeTreasure(field);

    while (1) {
        printField(field);

        char input;
        scanf(" %c", &input);

        switch (input) {
        case 'w':
            player.direction = 0;
            movePlayer(&player, field);
            break;
        case 'd':
            player.direction = 1;
            movePlayer(&player, field);
            break;
        case 's':
            player.direction = 2;
            movePlayer(&player, field);
            break;
        case 'a':
            player.direction = 3;
            movePlayer(&player, field);
            break;
        case 'q':
            return 0;
        }

        if (field[player.position.x][player.position.y] == 1) {
            printf("You found the treasure!\n");
            return 0;
        }
    }

    return 0;
}