//GEMINI-pro DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    int health;
    int attack;
    int defense;
} Entity;

Entity player;
Entity enemy;

void initializeGame() {
    srand(time(NULL));

    player.pos.x = 0;
    player.pos.y = 0;
    player.health = 100;
    player.attack = 10;
    player.defense = 5;

    enemy.pos.x = 10;
    enemy.pos.y = 10;
    enemy.health = 100;
    enemy.attack = 10;
    enemy.defense = 5;
}

void displayGame() {
    printf("Player: (%d, %d) Health: %d\n", player.pos.x, player.pos.y, player.health);
    printf("Enemy: (%d, %d) Health: %d\n", enemy.pos.x, enemy.pos.y, enemy.health);
}

void movePlayer() {
    int dx, dy;

    printf("Enter the direction (x, y): ");
    scanf("%d %d", &dx, &dy);

    player.pos.x += dx;
    player.pos.y += dy;
}

void moveEnemy() {
    int dx, dy;

    if (player.pos.x > enemy.pos.x) {
        dx = -1;
    } else if (player.pos.x < enemy.pos.x) {
        dx = 1;
    } else {
        dx = 0;
    }

    if (player.pos.y > enemy.pos.y) {
        dy = -1;
    } else if (player.pos.y < enemy.pos.y) {
        dy = 1;
    } else {
        dy = 0;
    }

    enemy.pos.x += dx;
    enemy.pos.y += dy;
}

void attack() {
    int damage;

    damage = player.attack - enemy.defense;
    if (damage < 0) {
        damage = 0;
    }

    enemy.health -= damage;

    printf("Player attacks enemy for %d damage!\n", damage);
}

void checkCollision() {
    if (player.pos.x == enemy.pos.x && player.pos.y == enemy.pos.y) {
        printf("Player has collided with enemy!\n");
    }
}

int main() {
    initializeGame();

    while (player.health > 0 && enemy.health > 0) {
        displayGame();
        movePlayer();
        moveEnemy();
        attack();
        checkCollision();
    }

    if (player.health <= 0) {
        printf("Player has died!\n");
    } else {
        printf("Enemy has died!\n");
    }

    return 0;
}