//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    int choice;
    int health = 100;
    int level = 1;
    int experience = 0;
    int enemyHealth = 50;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to defeat the evil dragon!\n\n");

    while (health > 0) {
        printf("You are currently at level %d with %d health points.\n", level, health);
        printf("You have %d experience points.\n\n", experience);

        printf("What would you like to do?\n");
        printf("1. Fight an enemy\n");
        printf("2. Rest\n");
        printf("3. Save game\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (level >= 5) {
                    enemyHealth = 75;
                } else if (level >= 3) {
                    enemyHealth = 60;
                } else {
                    enemyHealth = 50;
                }

                printf("You encounter an enemy with %d health points.\n", enemyHealth);
                printf("Press enter to attack...\n");
                getchar();

                if (rand() % 2 == 0) {
                    printf("You hit the enemy for 10 damage!\n");
                    enemyHealth -= 10;
                } else {
                    printf("You miss the enemy.\n");
                }

                if (enemyHealth <= 0) {
                    printf("You defeat the enemy and gain 10 experience points!\n");
                    experience += 10;
                } else {
                    printf("The enemy attacks you for 10 damage!\n");
                    health -= 10;
                }
                break;

            case 2:
                printf("You rest and regain 10 health points.\n");
                health += 10;
                break;

            case 3:
                printf("Game saved.\n");
                break;

            case 4:
                printf("Thanks for playing!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}