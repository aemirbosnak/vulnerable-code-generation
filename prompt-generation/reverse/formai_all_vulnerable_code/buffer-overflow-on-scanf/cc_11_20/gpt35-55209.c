//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("\nWelcome, %s, to the Land of Adventure!\n\n", name);

    int health = 50;
    int gold = 10;
    int level = 1;

    while (health > 0) {
        // Present the player with some options
        printf("You are currently level %d, with %d health and %d gold.\n", level, health, gold);
        printf("What do you want to do?\n");
        printf("1. Explore\n");
        printf("2. Shop\n");
        printf("3. Rest\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You venture forth into the unknown...\n");

                int success = rand() % 2;
                if (success) {
                    printf("You find a treasure chest! Inside, you find 20 gold.\n");
                    gold += 20;
                } else {
                    printf("You get ambushed by goblins! They steal 10 gold from you.\n");
                    gold -= 10;
                    health -= 10;
                }

                break;

            case 2:
                printf("You enter the local shop...\n");
                printf("What do you want to buy?\n");
                printf("1. Health potion: 10 gold\n");
                printf("2. Level up: 50 gold\n");

                int purchase;
                scanf("%d", &purchase);

                switch (purchase) {
                    case 1:
                        if (gold < 10) {
                            printf("You don't have enough gold to buy a health potion!\n");
                        } else {
                            printf("You purchase a health potion and restore 20 health.\n");
                            gold -= 10;
                            health += 20;
                        }
                        break;

                    case 2:
                        if (gold < 50) {
                            printf("You don't have enough gold to level up!\n");
                        } else {
                            printf("You level up and gain 50 health.\n");
                            gold -= 50;
                            health += 50;
                            level += 1;
                        }
                        break;

                    default:
                        printf("Invalid option.\n");
                        break;
                }

                break;

            case 3:
                printf("You decide to take a rest...\n");
                printf("Your health is restored to full.\n");
                health = 50;
                break;

            default:
                printf("Invalid option.\n");
                break;
        }

        if (health <= 0) {
            printf("You have died!\n");
            break;
        }
    }

    printf("Game over! You reached level %d with %d gold.\n", level, gold);
    return 0;
}