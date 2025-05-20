//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int chance = 50; // Chance of an encounter (percent)
    int health = 100; // Player's health (starts at 100)
    int score = 0; // Player's score (starts at 0)

    printf("\nWelcome to the Haunted House Simulator!\n");

    while (health > 0) { // Game loop
        printf("\nCurrent score: %d\n", score);
        printf("Current health: %d\n", health);

        if (rand() % 100 <= chance) { // Chance of an encounter
            printf("\nYou encounter a monster!\n");

            int monster_health = rand() % 101; // Monster's health (random between 0 and 100)

            while (health > 0 && monster_health > 0) { // Battle loop
                printf("\nWhat will you do?\n");
                printf("1. Attack (%d - %d damage)\n", 5, 15);
                printf("2. Defend (reduce monster's attack by 50%)\n");
                printf("3. Run away (take 10 damage)\n");

                int choice;
                printf("\nEnter your choice: ");
                scanf("%d", &choice);

                int damage;

                switch (choice) { // Player choice
                    case 1:
                        damage = rand() % 11 + 5; // Random damage between 5 and 15
                        printf("\nYou attack the monster and deal %d damage!\n", damage);
                        monster_health -= damage;
                        break;
                    case 2:
                        printf("\nYou defend yourself!\n");
                        break;
                    case 3:
                        printf("\nYou run away, but the monster catches up and deals 10 damage!\n");
                        health -= 10;
                        break;
                    default:
                        printf("\nInvalid choice!\n");
                        break;
                }

                if (monster_health > 0) { // Monster attack
                    damage = rand() % 16 + 5; // Random damage between 5 and 20
                    printf("\nThe monster attacks and deals %d damage!\n", damage);
                    health -= damage;
                }
            }

            if (health <= 0) { // Game over
                printf("\nYou died!\n");
                break;
            } else { // Victory
                printf("\nYou defeated the monster!\n");
                score += 10;
            }
        } else { // No encounter
            printf("\nYou continue to explore the haunted house...\n");
        }

        chance += 10; // Increase chance of an encounter every round
    }

    printf("\nGame over. Final score: %d\n", score);

    return 0;
}