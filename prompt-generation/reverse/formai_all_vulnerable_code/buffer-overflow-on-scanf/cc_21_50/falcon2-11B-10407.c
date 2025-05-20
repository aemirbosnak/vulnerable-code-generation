//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEALTH 100

int main() {
    // Initialize variables
    int health = MAX_HEALTH;
    int score = 0;
    int x = 0;
    int y = 0;
    int direction = 0; // 0 = north, 1 = east, 2 = south, 3 = west

    // Main loop
    while (1) {
        // Get user input
        printf("What would you like to do? (1-4)\n");
        int choice;
        scanf("%d", &choice);

        // Handle input
        switch (choice) {
            case 1: // Move north
                if (direction!= 3) {
                    y++;
                    direction = 0;
                } else {
                    printf("You can't move north anymore.\n");
                }
                break;
            case 2: // Move east
                if (direction!= 1) {
                    x++;
                    direction = 1;
                } else {
                    printf("You can't move east anymore.\n");
                }
                break;
            case 3: // Move south
                if (direction!= 0) {
                    y--;
                    direction = 2;
                } else {
                    printf("You can't move south anymore.\n");
                }
                break;
            case 4: // Move west
                if (direction!= 2) {
                    x--;
                    direction = 3;
                } else {
                    printf("You can't move west anymore.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Handle movement
        switch (direction) {
            case 0: // North
                if (y < MAX_HEALTH) {
                    health--;
                } else {
                    printf("You can't go any further north.\n");
                }
                break;
            case 1: // East
                if (x < MAX_HEALTH) {
                    health--;
                } else {
                    printf("You can't go any further east.\n");
                }
                break;
            case 2: // South
                if (y > 0) {
                    health--;
                } else {
                    printf("You can't go any further south.\n");
                }
                break;
            case 3: // West
                if (x > 0) {
                    health--;
                } else {
                    printf("You can't go any further west.\n");
                }
                break;
            default:
                break;
        }

        // Handle combat
        if (health > 0) {
            int enemy_health = rand() % 10 + 1;
            printf("You encounter an enemy! %d HP\n", enemy_health);
            printf("What do you want to do? (1-2)\n");
            int choice2;
            scanf("%d", &choice2);
            switch (choice2) {
                case 1: // Fight
                    printf("You fight the enemy!\n");
                    health -= 1;
                    enemy_health -= 1;
                    if (enemy_health <= 0) {
                        score++;
                        printf("You win the fight!\n");
                        break;
                    } else if (health <= 0) {
                        printf("You lose the fight!\n");
                        break;
                    }
                case 2: // Run
                    printf("You run away!\n");
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
        } else {
            printf("You are dead!\n");
            break;
        }

        // Handle exploration
        printf("Score: %d\n", score);

        // Print grid
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 || j == 0 || i == 9 || j == 9) {
                    printf("#");
                } else if (i == y && j == x) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}