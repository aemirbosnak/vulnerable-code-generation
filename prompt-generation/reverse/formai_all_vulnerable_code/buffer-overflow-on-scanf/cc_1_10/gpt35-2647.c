//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize variables
    int choice, monster, player_hp = 10, monster_hp = 10;
    srand(time(0));  // Seed random number generator with current time

    // Print game introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a warrior on a quest to defeat a monster.\n");

    // Game loop
    do {
        printf("\nYou have %d health points remaining.\n\n", player_hp);
        printf("Choose your action:\n");
        printf("1. Attack\n");
        printf("2. Defend\n");
        printf("3. Run\n");

        // Get player's choice
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Player attacks monster
                printf("You strike the monster!\n");
                monster = rand() % 4;  // Generate random number between 0-3
                if (monster == 0) {
                    // Monster dodges attack
                    printf("But the monster dodges your attack!\n");
                } else {
                    // Monster takes damage
                    monster_hp -= 1 + rand() % 3;  // Random damage between 1-3
                    printf("You deal %d damage to the monster!\n", monster_hp);
                }
                break;

            case 2:
                // Player defends
                printf("You prepare to defend against the monster's attack.\n");
                monster = rand() % 4;
                if (monster == 0) {
                    // Monster does not attack
                    printf("The monster hesitates to attack.\n");
                } else {
                    // Monster attacks player
                    printf("The monster strikes at you!\n");
                    player_hp -= rand() % 4;  // Random damage between 0-3
                    printf("You take %d damage!\n", player_hp);
                }
                break;

            case 3:
                // Player attempts to run away
                printf("You try to run away from the monster...\n");
                monster = rand() % 4;
                if (monster == 0) {
                    // Monster catches player
                    printf("But the monster blocks your escape!\n");
                } else {
                    // Player successfully escapes
                    printf("You manage to escape from the monster!\n");
                    exit(0);  // End program
                }
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (player_hp > 0 && monster_hp > 0);

    // Print game over message
    if (player_hp <= 0) {
        printf("You have been defeated by the monster. Game over.\n");
    } else {
        printf("You have defeated the monster! Congratulations!\n");
    }

    return 0;
}