//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int health = 100;
    int score = 0;

    srand(time(0));

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer exploring a mysterious land.\n");
    printf("Your goal is to survive as long as possible and collect as many treasures as you can.\n");

    while (health > 0) {
        printf("\n");
        printf("You are standing in front of a fork in the road.\n");
        printf("Which path will you choose?\n");
        printf("1. Left\n");
        printf("2. Right\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("You walk down the left path and find a treasure chest!\n");
                printf("You open it and find a magical potion that restores 50 health points.\n");
                health += 50;
                score += 10;
                break;
            case 2:
                printf("\n");
                printf("You walk down the right path and encounter a fierce dragon!\n");
                printf("Do you want to fight the dragon or run away?\n");
                printf("1. Fight\n");
                printf("2. Run\n");
                scanf("%d", &choice);

                switch (choice) {
                    case 1:
                        printf("\n");
                        printf("You engage in a fierce battle with the dragon.\n");
                        printf("Roll a virtual dice to determine your attack power.\n");
                        int dice = rand() % 6 + 1;
                        printf("You rolled a %d!\n", dice);
                        if (dice >= 4) {
                            printf("You defeat the dragon and find a treasure chest!\n");
                            printf("You open it and find a magical potion that restores 75 health points.\n");
                            health += 75;
                            score += 20;
                        } else {
                            printf("The dragon defeats you. Game over.\n");
                            return 0;
                        }
                        break;
                    case 2:
                        printf("\n");
                        printf("You run away from the dragon as fast as you can.\n");
                        break;
                }
                break;
            default:
                printf("\n");
                printf("Invalid choice. Try again.\n");
        }
    }

    printf("\n");
    printf("Game over. Your final score is %d.\n", score);

    return 0;
}