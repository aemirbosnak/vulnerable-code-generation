//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int health = 100;
    int gold = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You start in a small village with 100 health and 0 gold.\n");
    printf("What would you like to do?\n");
    printf("1. Explore the village\n");
    printf("2. Go to the forest\n");
    printf("3. Quit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You explore the village and find a potion.\n");
            printf("Do you want to drink it? (y/n)\n");
            char potion;
            scanf(" %c", &potion);
            if(potion == 'y' || potion == 'Y') {
                printf("You drink the potion and gain 50 health.\n");
                health += 50;
            } else {
                printf("You leave the potion behind.\n");
            }
            break;
        case 2:
            printf("You go to the forest and find a treasure chest.\n");
            printf("Do you want to open it? (y/n)\n");
            char chest;
            scanf(" %c", &chest);
            if(chest == 'y' || chest == 'Y') {
                printf("You open the chest and find 50 gold.\n");
                gold += 50;
            } else {
                printf("You leave the chest behind.\n");
            }
            break;
        case 3:
            printf("Thanks for playing!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}