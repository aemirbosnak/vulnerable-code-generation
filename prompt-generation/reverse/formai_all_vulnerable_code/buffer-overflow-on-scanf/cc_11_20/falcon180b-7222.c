//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playerName[20];
    int health = 100;
    int gold = 0;
    int choice;
    int randomEnemy = rand() % 3 + 1;

    printf("Enter your name: ");
    scanf("%s", playerName);

    printf("\nWelcome to the world of %s!\n", playerName);
    printf("You have %d health points and %d gold coins.\n", health, gold);

    while(health > 0) {
        system("clear"); // clear the console

        printf("\nYou are in a dark forest.\n");
        printf("To the north, you see a castle.\n");
        printf("To the east, you see a river.\n");
        printf("To the west, you see a mountain.\n");
        printf("What do you want to do?\n");
        printf("1. Go north\n");
        printf("2. Go east\n");
        printf("3. Go west\n");
        printf("4. Check inventory\n");
        printf("5. Save game\n");
        printf("6. Quit\n");
        printf("> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(gold >= 50) {
                    printf("\nYou enter the castle and find a treasure chest.\n");
                    printf("You gained 50 gold coins!\n");
                    gold += 50;
                } else {
                    printf("\nYou don't have enough gold to enter the castle.\n");
                }
                break;
            case 2:
                printf("\nYou follow the river and find a hidden cave.\n");
                printf("Inside the cave, you find a magical potion.\n");
                printf("You gained 25 health points!\n");
                health += 25;
                break;
            case 3:
                printf("\nYou climb the mountain and find a wise old man.\n");
                printf("He teaches you a powerful spell.\n");
                printf("You gained a new ability: Fireball!\n");
                break;
            case 4:
                printf("\nInventory:\n");
                printf("- %d gold coins\n", gold);
                printf("- %d health points\n", health);
                if(health > 50) {
                    printf("- Fireball spell\n");
                }
                break;
            case 5:
                printf("\nGame saved.\n");
                break;
            case 6:
                printf("\nThanks for playing!\n");
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }

        if(randomEnemy == 1) {
            printf("\nA giant spider attacks you!\n");
            health -= 25;
        } else if(randomEnemy == 2) {
            printf("\nA group of goblins steal some of your gold!\n");
            gold -= 25;
        }

        system("sleep 1"); // pause for 1 second
    }

    printf("\nGame over. You died.\n");
    return 0;
}