//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Initialize variables
    int option, action, health = 100, enemy_health = 100, attack_power, enemy_attack_power;
    char name[20];

    printf("Welcome traveller! What's your name? ");
    scanf("%s", &name);

    // Introduction
    printf("Greetings %s. You have stumbled upon a dungeon. Do you want to enter? (1 for Yes, 0 for No) ", name);
    scanf("%d", &option);

    if(option == 0) {
        printf("You decide to turn back. Goodbye %s.\n", name);
        return 0;
    }

    printf("\nGreat! Let the adventure begin!\n");

    // Game Loop
    while(health > 0 && enemy_health > 0) {
        printf("\nYour health: %d  Enemy health: %d\n", health, enemy_health);
        printf("What do you want to do? (1 for Attack, 0 for Defend) ");
        scanf("%d", &action);

        if(action == 0) {
            printf("You choose to defend. You don't take any damage.\n");
        }
        else {
            // Calculate attack power
            srand(time(NULL));
            attack_power = rand() % 20 + 1; // Generate a random number between 1 and 20
            enemy_attack_power = rand() % 20 + 1;

            printf("You attack with a power of %d.\n", attack_power);
            printf("The enemy attacks with a power of %d.\n", enemy_attack_power);

            // Calculate damage
            enemy_health -= attack_power;
            health -= enemy_attack_power;

            printf("You deal %d damage to the enemy.\n", attack_power);
            printf("The enemy deals %d damage to you.\n", enemy_attack_power);
        }
    }

    // End of Game
    if(health <= 0) {
        printf("You have been defeated by the enemy. Game over.\n");
    }
    else {
        printf("Congratulations %s! You have defeated the enemy. You win!\n", name);
    }

    return 0;
}