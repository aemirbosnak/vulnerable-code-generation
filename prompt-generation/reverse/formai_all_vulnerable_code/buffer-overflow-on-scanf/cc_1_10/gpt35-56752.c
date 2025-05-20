//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ENEMIES 3

struct Position {
    int x;
    int y;
};

struct Enemy {
    char name[20];
    int health;
    struct Position position;
};

struct Player {
    char name[20];
    int health;
    struct Position position;
};

void printMap(char map[][MAP_SIZE]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        printf("| ");
        for(int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map[i][j]);
        }
        printf("|\n");
    }
}

int checkCollision(struct Player player, struct Enemy enemy) {
    if(player.position.x == enemy.position.x && player.position.y == enemy.position.y) {
        return 1;
    }
    return 0;
}

void initEnemies(struct Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        sprintf(enemies[i].name, "Enemy-%d", i + 1);
        enemies[i].health = 100;
        enemies[i].position.x = rand() % MAP_SIZE;
        enemies[i].position.y = rand() % MAP_SIZE;
    }
}

void initPlayer(struct Player *player) {
    printf("Enter player name: ");
    scanf("%s", player->name);
    player->health = 100;
    player->position.x = rand() % MAP_SIZE;
    player->position.y = rand() % MAP_SIZE;
}

void movePlayer(char map[][MAP_SIZE], struct Player *player, int x, int y) {
    if(map[player->position.y + y][player->position.x + x] != '#') {
        player->position.x += x;
        player->position.y += y;
    }
}

void updateMap(char map[][MAP_SIZE], struct Player player, struct Enemy enemies[]) {
    for(int i = 0; i < MAP_SIZE; i++) {
        for(int j = 0; j < MAP_SIZE; j++) {
            if(i == player.position.y && j == player.position.x) {
                map[i][j] = 'P';
            }
            else {
                map[i][j] = '-';
            }
        }
    }
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].health > 0) {
            map[enemies[i].position.y][enemies[i].position.x] = 'E';
        }
    }
}

void playGame() {
    char map[MAP_SIZE][MAP_SIZE];
    struct Player player;
    struct Enemy enemies[MAX_ENEMIES];
    int numAliveEnemies = MAX_ENEMIES;

    initPlayer(&player);
    initEnemies(enemies);
    updateMap(map, player, enemies);

    while(numAliveEnemies > 0 && player.health > 0) {
        printMap(map);

        int x, y;
        printf("Enter move: ");
        scanf("%d %d", &x, &y);
        movePlayer(map, &player, x, y);

        for(int i = 0; i < MAX_ENEMIES; i++) {
            if(checkCollision(player, enemies[i]) && enemies[i].health > 0) {
                enemies[i].health -= 50;
                if(enemies[i].health <= 0) {
                    numAliveEnemies--;
                }
            }
        }

        updateMap(map, player, enemies);
    }

    if(numAliveEnemies == 0) {
        printf("Congratulations! You have defeated all enemies!\n");
    }
    else {
        printf("Game Over! You were defeated!\n");
    }
}

int main() {
    srand(time(NULL));
    playGame();

    return 0;
}