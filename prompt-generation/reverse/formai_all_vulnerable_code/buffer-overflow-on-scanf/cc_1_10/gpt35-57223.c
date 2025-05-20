//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeRandomSeed() {
    srand(time(0));
}

int randomInRange(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int shield;
    int laser;
    int hull;
} Ship;

typedef struct {
    Position position;
    Ship ship;
} Player;

typedef struct {
    Position position;
    int health;
} Enemy;

void movePlayer(Player *player, char direction) {
    switch(direction) {
        case 'U':
            player->position.y++;
            break;
        case 'D':
            player->position.y--;
            break;
        case 'L':
            player->position.x--;
            break;
        case 'R':
            player->position.x++;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}

int main() {
    initializeRandomSeed();
    Player player = {{0,0}, {100, 50, 100}};
    Enemy enemy = {{randomInRange(-10, 10), randomInRange(-10, 10)}, 50};
    int playerScore = 0;
    int turnCounter = 1;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your ship has 100 Shield, 50 Laser, and 100 Hull.\n");
    printf("Turn 1\n");
    printf("Current position: (%d,%d)\n", player.position.x, player.position.y);

    while(player.ship.hull > 0 && enemy.health > 0) {
        printf("Enter direction (U/D/L/R): ");
        char direction;
        scanf(" %c", &direction);
        movePlayer(&player, direction);

        printf("Current position: (%d,%d)\n", player.position.x, player.position.y);

        if(turnCounter % 3 == 0) {
            int laserDamage = randomInRange(5, 15);
            player.ship.laser -= laserDamage;
            if(player.ship.laser <= 0) {
                player.ship.hull -= -player.ship.laser;
                player.ship.laser = 0;
            }
            printf("Enemy laser hits for %d damage! [Laser: %d, Hull: %d]\n", laserDamage, player.ship.laser, player.ship.hull);
        }

        if(turnCounter % 4 == 0) {
            int enemyMovement = randomInRange(1, 10);
            enemy.position.x += (randomInRange(-1, 1) * enemyMovement);
            enemy.position.y += (randomInRange(-1, 1) * enemyMovement);
            printf("Enemy moved: (%d,%d)\n", enemy.position.x, enemy.position.y);
        }

        if(player.position.x == enemy.position.x && player.position.y == enemy.position.y) {
            int shieldDamage = randomInRange(10, 20);
            player.ship.shield -= shieldDamage;
            if(player.ship.shield < 0) {
                player.ship.hull += player.ship.shield;
                player.ship.shield = 0;
            }
            int hullDamage = randomInRange(5, 15);
            player.ship.hull -= hullDamage;
            printf("Enemy attacks for %d Shield and %d Hull damage! [Shield: %d, Hull: %d]\n", shieldDamage, hullDamage, player.ship.shield, player.ship.hull);
        }

        turnCounter++;

        if(turnCounter % 5 == 0) {
            int enemyDamage = randomInRange(5, 15);
            enemy.health -= enemyDamage;
            printf("Your laser hits for %d damage! [Health: %d]\n", enemyDamage, enemy.health);
        }

        if(turnCounter % 10 == 0) {
            int item = randomInRange(1, 3);
            switch(item) {
                case 1:
                    player.ship.shield += randomInRange(5, 15);
                    printf("You found a Shield regeneration pack! [+%d Shield]\n", player.ship.shield);
                    break;
                case 2:
                    player.ship.laser += randomInRange(5, 15);
                    printf("You found a Laser ammunition pack! [+%d Laser]\n", player.ship.laser);
                    break;
                case 3:
                    player.ship.hull += randomInRange(5, 15);
                    printf("You found a Hull repair pack! [+%d Hull]\n", player.ship.hull);
                    break;
            }
        }
    }

    printf("Game over!\n");

    if(enemy.health <= 0) {
        playerScore += 1000 + (100 * turnCounter) - (10 * (enemy.position.x + enemy.position.y));
        printf("Victory! Enemy destroyed.\n");
    } else {
        playerScore += 50 * turnCounter - (10 * (enemy.position.x + enemy.position.y));
        printf("Defeat! Your ship was destroyed.\n");
    }

    printf("Score: %d\n", playerScore);

    return 0;
}