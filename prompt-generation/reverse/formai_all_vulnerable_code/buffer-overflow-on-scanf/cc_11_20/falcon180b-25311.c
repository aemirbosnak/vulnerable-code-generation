//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer in search of treasure.\n");
    printf("Guide me through this adventure.\n");
    scanf("%d", &choice);

    int health = 100;
    int treasure = 0;

    while(health > 0 && treasure == 0) {
        switch(choice) {
            case 1:
                printf("You decide to explore the dark forest.\n");
                if(rand() % 2 == 0) {
                    printf("You find a hidden path that leads to a cave.\n");
                    printf("Do you want to enter the cave? (y/n)\n");
                    char cave;
                    scanf("%c", &cave);
                    if(cave == 'y' || cave == 'Y') {
                        printf("You enter the cave and find a treasure chest!\n");
                        treasure = 1;
                    } else {
                        printf("You decide to leave the cave and continue your journey.\n");
                    }
                } else {
                    printf("You get lost in the forest and lose 10 health points.\n");
                    health -= 10;
                }
                break;
            case 2:
                printf("You decide to cross the treacherous river.\n");
                if(rand() % 2 == 0) {
                    printf("You successfully cross the river.\n");
                } else {
                    printf("You are swept away by the current and lose 20 health points.\n");
                    health -= 20;
                }
                break;
            case 3:
                printf("You decide to climb the steep mountain.\n");
                if(rand() % 2 == 0) {
                    printf("You reach the top of the mountain and find a treasure chest!\n");
                    treasure = 1;
                } else {
                    printf("You slip and fall, losing 30 health points.\n");
                    health -= 30;
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
        printf("Your current health is %d.\n", health);
    }

    if(treasure == 1) {
        printf("Congratulations! You have found the treasure and completed the adventure.\n");
    } else {
        printf("Game over. You did not find the treasure.\n");
    }

    return 0;
}