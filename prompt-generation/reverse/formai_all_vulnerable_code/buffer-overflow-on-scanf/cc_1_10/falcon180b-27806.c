//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int choice;
    int health = 100;
    int score = 0;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You wake up in a mysterious forest. What will you do?\n");
    printf("1. Explore the forest\n2. Look for food\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("As you walk deeper into the forest, you come across a river.\n");
            printf("Do you want to cross the river? (y/n)\n");
            char river;
            scanf(" %c", &river);

            if(river == 'y' || river == 'Y') {
                printf("You successfully crossed the river.\n");
                score += 10;
            } else {
                printf("You decided not to cross the river.\n");
            }
            break;

        case 2:
            printf("You search for food and find some berries.\n");
            printf("Do you want to eat the berries? (y/n)\n");
            char berries;
            scanf(" %c", &berries);

            if(berries == 'y' || berries == 'Y') {
                printf("The berries were delicious! You gained 20 health points.\n");
                health += 20;
            } else {
                printf("You decided not to eat the berries.\n");
            }
            break;

        default:
            printf("Invalid choice. Try again.\n");
            return 0;
    }

    printf("Your current health is %d and your score is %d.\n", health, score);
    printf("Do you want to continue exploring the forest? (y/n)\n");
    char continueGame;
    scanf(" %c", &continueGame);

    if(continueGame == 'y' || continueGame == 'Y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}