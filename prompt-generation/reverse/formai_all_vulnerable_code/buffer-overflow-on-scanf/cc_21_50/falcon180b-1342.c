//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerX = 0, playerY = 0, playerZ = 0;
    int shipX = 0, shipY = 0, shipZ = 0;
    int enemyX = 0, enemyY = 0, enemyZ = 0;
    int choice;
    char playAgain = 'y';

    printf("Welcome to the Space Adventure!\n");
    printf("You are a space explorer on a mission to defeat the enemy ship.\n");
    printf("You start at coordinates (0,0,0).\n");
    printf("The enemy ship starts at coordinates (0,0,1000).\n");
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Move left\n");
    printf("4. Move right\n");
    printf("5. Attack\n");
    scanf("%d", &choice);

    while (playAgain == 'y') {
        switch (choice) {
            case 1:
                playerX++;
                printf("You moved forward.\n");
                break;
            case 2:
                playerX--;
                printf("You moved backward.\n");
                break;
            case 3:
                playerY--;
                printf("You moved left.\n");
                break;
            case 4:
                playerY++;
                printf("You moved right.\n");
                break;
            case 5:
                if (playerX == shipX && playerY == shipY && playerZ == shipZ) {
                    printf("You attacked the enemy ship and won!\n");
                    playAgain = 'n';
                } else {
                    printf("You missed the enemy ship.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (playerX < 0 || playerX > 1000 || playerY < 0 || playerY > 1000 || playerZ < 0 || playerZ > 1000) {
            printf("You are out of bounds. Game over.\n");
            playAgain = 'n';
        }

        if (enemyX < 0 || enemyX > 1000 || enemyY < 0 || enemyY > 1000 || enemyZ < 0 || enemyZ > 1000) {
            printf("The enemy ship is out of bounds. Game over.\n");
            playAgain = 'n';
        }

        if (playerX == enemyX && playerY == enemyY && playerZ == enemyZ) {
            printf("You collided with the enemy ship. Game over.\n");
            playAgain = 'n';
        }
    }

    return 0;
}