//GPT-4o-mini DATASET v1.0 Category: Text-Based Adventure Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro() {
    printf("Welcome to the Mysterious Forest Adventure!\n");
    printf("Your goal is to find the hidden treasure.\n");
    printf("Make wise choices to survive the forest.\n");
}

void forestPath() {
    printf("\nYou are at a fork in the road.\n");
    printf("Do you want to go left (1) or right (2)? ");
}

void leftPath() {
    printf("\nYou walked into a dark part of the forest.\n");
    printf("Suddenly, you see a bear!\n");
    printf("Do you want to fight the bear (1) or run away (2)? ");
}

void rightPath() {
    printf("\nYou walk along a bright path filled with flowers.\n");
    printf("You see an old man sitting under a tree.\n");
    printf("Do you want to talk to him (1) or ignore him (2)? ");
}

void bearEncounter() {
    printf("\nYou decide to fight the bear!\n");
    printf("The bear is strong and you are injured.\n");
    printf("You lose the fight and unfortunately, you die.\n");
    exit(0);
}

void runFromBear() {
    printf("\nYou managed to run away from the bear!\n");
    printf("You find a river.\n");
    printf("Do you want to swim across (1) or walk along the bank (2)? ");
}

void talkToOldMan() {
    printf("\nThe old man gives you a map to the treasure!\n");
    printf("Feeling grateful, you follow the map to a clearing.\n");
    printf("You see the treasure chest!\n");
    printf("Congratulations! You have found the treasure!\n");
    exit(0);
}

void ignoreOldMan() {
    printf("\nYou ignored the old man and continued your journey.\n");
    printf("Unfortunately, you got lost and could not find the treasure.\n");
    printf("Game Over.\n");
    exit(0);
}

void swimAcross() {
    printf("\nYou swim across the river and find another path.\n");
    printf("You find the treasure chest!\n");
    printf("Congratulations! You have found the treasure!\n");
    exit(0);
}

void walkAlongBank() {
    printf("\nYou walk along the bank and arrive at another fork.\n");
    printf("Do you want to go left (1) or right (2)? ");
}

void lostInWoods() {
    printf("\nYou wandered too far and are now lost in the woods.\n");
    printf("Nobody can help you now.\n");
    printf("Game Over.\n");
    exit(0);
}

int main() {
    int choice;

    intro();

    forestPath();
    scanf("%d", &choice);
    if (choice == 1) {
        leftPath();
        scanf("%d", &choice);
        if (choice == 1) {
            bearEncounter();
        } else if (choice == 2) {
            runFromBear();
            scanf("%d", &choice);
            if (choice == 1) {
                swimAcross();
            } else {
                walkAlongBank();
                scanf("%d", &choice);
                if (choice == 1) {
                    lostInWoods();
                } else {
                    lostInWoods();
                }
            }
        }
    } else if (choice == 2) {
        rightPath();
        scanf("%d", &choice);
        if (choice == 1) {
            talkToOldMan();
        } else {
            ignoreOldMan();
        }
    } else {
        printf("Invalid choice! Please restart the game.\n");
    }

    return 0;
}