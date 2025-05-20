//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int enemyHealth = 100;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to defeat the evil dragon.\n");
    printf("Choose your path wisely, for danger lurks around every corner.\n");
    printf("Press enter to begin.\n");
    getchar();

    while (health > 0 && enemyHealth > 0) {
        printf("\nYou are standing in a dark forest. What do you want to do?\n");
        printf("1. Attack the dragon\n2. Defend yourself\n3. Run away\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You charge towards the dragon with your sword raised high...\n");
                if (rand() % 2 == 1) {
                    printf("The dragon breathes fire at you, dealing 50 damage!\n");
                    health -= 50;
                } else {
                    printf("You strike the dragon with your sword, dealing 25 damage!\n");
                    enemyHealth -= 25;
                }
                break;
            case 2:
                printf("You raise your shield and prepare for the dragon's attack...\n");
                if (rand() % 2 == 1) {
                    printf("The dragon's claws hit your shield, dealing no damage.\n");
                } else {
                    printf("The dragon breathes fire at you, dealing 50 damage!\n");
                    health -= 50;
                }
                break;
            case 3:
                printf("You turn and run as fast as you can...\n");
                printf("The dragon chases after you, but you manage to escape unscathed.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (health <= 0) {
            printf("\nYou have been defeated by the dragon. Game over.\n");
            return 0;
        } else if (enemyHealth <= 0) {
            printf("\nYou have defeated the dragon! Congratulations!\n");
            return 0;
        }
    }
}