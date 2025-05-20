//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    int x;
    int y;
    int health;
    int ammo;
};

struct Enemy {
    int x;
    int y;
    int health;
    int damage;
};

struct Player generatePlayer() {
    struct Player player;
    player.x = 5;
    player.y = 5;
    player.health = 100;
    player.ammo = 20;
    return player;
}

struct Enemy generateEnemy() {
    struct Enemy enemy;
    enemy.x = rand() % 10;
    enemy.y = rand() % 10;
    enemy.health = 50;
    enemy.damage = 10;
    return enemy;
}

int movePlayer(struct Player *player, int direction) {
    switch (direction) {
        case 1: // up
            if (player->y > 0) {
                player->y--;
                return 1;
            }
            break;
        case 2: // down
            if (player->y < 9) {
                player->y++;
                return 1;
            }
            break;
        case 3: // left
            if (player->x > 0) {
                player->x--;
                return 1;
            }
            break;
        case 4: // right
            if (player->x < 9) {
                player->x++;
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}

int attackEnemy(struct Player *player, struct Enemy *enemy) {
    if (player->ammo > 0) {
        enemy->health -= 20;
        player->ammo--;
        if (enemy->health <= 0) {
            return 2; // enemy dead
        }
        return 1; // hit enemy
    }
    return 0; // out of ammo
}

int attackPlayer(struct Player *player, struct Enemy *enemy) {
    player->health -= enemy->damage;
    if (player->health <= 0) {
        return 2; // player dead
    }
    return 1; // hit player
}

void displayMap(struct Player player, struct Enemy enemy) {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == player.y && j == player.x) {
                printf("P");
            } else if (i == enemy.y && j == enemy.x) {
                printf("E");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    struct Player player = generatePlayer();
    struct Enemy enemy = generateEnemy();
    int gameOver = 0;
    while (!gameOver) {
        displayMap(player, enemy);
        printf("Health: %d, Ammo: %d\n", player.health, player.ammo);
        int direction;
        printf("Enter direction to move (1. up, 2. down, 3. left, 4. right): ");
        scanf("%d", &direction);
        int moved = movePlayer(&player, direction);
        if (!moved) {
            printf("Invalid move!\n");
            continue;
        }
        int attackChance = rand() % 2;
        if (attackChance == 1) {
            int attackResult = attackPlayer(&player, &enemy);
            if (attackResult == 2) {
                printf("Game over! Player is dead.\n");
                gameOver = 1;
            } else if (attackResult == 1) {
                printf("Player is hit! Health: %d\n", player.health);
            }
        } else {
            int attackResult = attackEnemy(&player, &enemy);
            if (attackResult == 2) {
                printf("Hooray! Enemy is dead.\n");
                enemy = generateEnemy();
            } else if (attackResult == 1) {
                printf("Enemy is hit! Health: %d\n", enemy.health);
            } else {
                printf("Out of ammo!\n");
            }
        }
    }
    return 0;
}