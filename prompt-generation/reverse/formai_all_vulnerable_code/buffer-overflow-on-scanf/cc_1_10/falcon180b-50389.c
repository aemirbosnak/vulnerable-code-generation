//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int gold = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest for treasure.\n");
    printf("Guide me through the adventure.\n");

    while(health > 0) {
        system("clear");
        printf("You are in a dark, damp cave.\n");
        printf("There are three paths to choose from:\n1. Left\n2. Right\n3. Forward\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("You take the left path and find a treasure chest!\n");
                printf("You gained 50 gold!\n");
                gold += 50;
                break;
            case 2:
                printf("You take the right path and find a healing potion!\n");
                printf("You regained 25 health!\n");
                health += 25;
                break;
            case 3:
                printf("You move forward and encounter a fierce dragon!\n");
                printf("You lost 25 health in the battle.\n");
                health -= 25;
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("Health: %d\nGold: %d\n", health, gold);
    }

    if(gold > 0) {
        printf("You have completed the adventure with %d gold!\n", gold);
    } else {
        printf("You have failed the adventure.\n");
    }

    return 0;
}