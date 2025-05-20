//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIVES 3

typedef struct {
    int x, y;
} Position;

Position player;
Position enemy;

void initializeGame() {
    player.x = enemy.x = 0;
    player.y = enemy.y = 0;
}

void movePlayer(int dx, int dy) {
    player.x += dx;
    player.y += dy;
}

void attackEnemy() {
    if (player.x == enemy.x && player.y == enemy.y) {
        enemy.x = enemy.y = -1;
    }
}

void drawGame() {
    system("clear");
    printf("Player: (%d, %d)\n", player.x, player.y);
    printf("Enemy: (%d, %d)\n", enemy.x, enemy.y);

    if (enemy.x == -1) {
        printf("You win!\n");
    } else if (player.x == -1) {
        printf("Game over!\n");
    }
}

int main() {
    initializeGame();

    while (player.x != -1 && enemy.x != -1) {
        drawGame();

        int dx, dy;
        printf("Enter move (dx, dy): ");
        scanf("%d %d", &dx, &dy);

        movePlayer(dx, dy);
        attackEnemy();
    }

    return 0;
}