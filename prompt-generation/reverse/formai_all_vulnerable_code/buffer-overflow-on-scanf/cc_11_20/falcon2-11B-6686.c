//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYER_HEALTH 100
#define MAX_ENEMY_HEALTH 75
#define PLAYER_DAMAGE 10
#define ENEMY_DAMAGE 5
#define MAX_ENEMIES 3

int main() {
    srand(time(NULL));
    int playerHealth = MAX_PLAYER_HEALTH;
    int enemyHealth[MAX_ENEMIES];
    int numEnemies = rand() % MAX_ENEMIES + 1;

    printf("Welcome to the Space Adventure!\n");
    printf("You are the last surviving member of a space exploration team.\n");
    printf("Your mission is to destroy the alien mothership before it destroys Earth.\n");

    while (playerHealth > 0 && numEnemies > 0) {
        printf("You are in a spaceship, surrounded by asteroids and debris.\n");
        printf("You hear the sound of an approaching spaceship.\n");

        enemyHealth[numEnemies - 1] = rand() % MAX_ENEMY_HEALTH + 1;
        printf("An alien spaceship appears, and you can see the alien warriors inside.\n");
        printf("They are firing lasers at you!\n");

        printf("What do you do?\n");
        printf("1. Fire back\n");
        printf("2. Retreat\n");
        printf("3. Scan the ship\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You fire back, and hit the alien spaceship!\n");
                printf("You take %d damage.\n", ENEMY_DAMAGE);
                playerHealth -= ENEMY_DAMAGE;
                if (playerHealth <= 0) {
                    printf("You are dead.\n");
                    break;
                }
                printf("You fire back, and hit the alien warriors!\n");
                printf("They take %d damage.\n", PLAYER_DAMAGE);
                enemyHealth[numEnemies - 1] -= PLAYER_DAMAGE;
                if (enemyHealth[numEnemies - 1] <= 0) {
                    numEnemies--;
                }
                break;
            case 2:
                printf("You retreat, and hide behind an asteroid.\n");
                printf("The alien spaceship follows you.\n");
                printf("What do you do?\n");
                printf("1. Fire back\n");
                printf("2. Retreat further\n");
                printf("3. Scan the ship\n");

                choice = 0;
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("You fire back, and hit the alien spaceship!\n");
                        printf("You take %d damage.\n", ENEMY_DAMAGE);
                        playerHealth -= ENEMY_DAMAGE;
                        if (playerHealth <= 0) {
                            printf("You are dead.\n");
                            break;
                        }
                        printf("You fire back, and hit the alien warriors!\n");
                        printf("They take %d damage.\n", PLAYER_DAMAGE);
                        enemyHealth[numEnemies - 1] -= PLAYER_DAMAGE;
                        if (enemyHealth[numEnemies - 1] <= 0) {
                            numEnemies--;
                        }
                        break;
                    case 2:
                        printf("You retreat further, and hide behind a larger asteroid.\n");
                        printf("The alien spaceship follows you.\n");
                        printf("What do you do?\n");
                        printf("1. Fire back\n");
                        printf("2. Retreat further\n");
                        printf("3. Scan the ship\n");

                        choice = 0;
                        scanf("%d", &choice);

                        switch (choice) {
                            case 1:
                                printf("You fire back, and hit the alien spaceship!\n");
                                printf("You take %d damage.\n", ENEMY_DAMAGE);
                                playerHealth -= ENEMY_DAMAGE;
                                if (playerHealth <= 0) {
                                    printf("You are dead.\n");
                                    break;
                                }
                                printf("You fire back, and hit the alien warriors!\n");
                                printf("They take %d damage.\n", PLAYER_DAMAGE);
                                enemyHealth[numEnemies - 1] -= PLAYER_DAMAGE;
                                if (enemyHealth[numEnemies - 1] <= 0) {
                                    numEnemies--;
                                }
                                break;
                            case 3:
                                printf("You scan the ship, and discover a weakness.\n");
                                printf("You fire back, and hit the alien warriors!\n");
                                printf("They take %d damage.\n", PLAYER_DAMAGE);
                                enemyHealth[numEnemies - 1] -= PLAYER_DAMAGE;
                                if (enemyHealth[numEnemies - 1] <= 0) {
                                    numEnemies--;
                                }
                                break;
                        }
                        break;
                }
                break;
            case 3:
                printf("You scan the ship, and discover a weakness.\n");
                printf("You fire back, and hit the alien warriors!\n");
                printf("They take %d damage.\n", PLAYER_DAMAGE);
                enemyHealth[numEnemies - 1] -= PLAYER_DAMAGE;
                if (enemyHealth[numEnemies - 1] <= 0) {
                    numEnemies--;
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    if (numEnemies == 0) {
        printf("You have destroyed the alien mothership!\n");
        printf("You have saved Earth!\n");
    } else {
        printf("You have been defeated by the alien mothership.\n");
        printf("Earth has been destroyed.\n");
    }

    return 0;
}