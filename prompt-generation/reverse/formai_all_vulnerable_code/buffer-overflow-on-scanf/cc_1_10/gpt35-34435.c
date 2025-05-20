//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // To generate random numbers each time

    // Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are about to embark on a journey through a magical land.\n\n");

    // Variables to keep track of player's status
    int health = 100;
    int gold = 0;
    int items = 0;

    // Prompt user to begin game
    printf("Are you ready to begin? (y/n)\n");
    char answer;
    scanf("%c", &answer);

    // If user does not want to play, end game
    if(answer == 'n') {
        printf("Alright, come back next time!\n");
        return 0;
    }

    // Storyline and first decision
    printf("\nYou start your journey on a path through a dense forest.\n");
    printf("As you walk, you notice a fork in the road.\n");
    printf("Do you take the path on the left (1) or the right (2)?\n");

    int decision1;
    scanf("%d", &decision1);

    // Random encounter depending on player's decision
    if(decision1 == 1) {
        printf("\nYou take the path on the left and continue walking.\n");
        printf("Suddenly, a group of trolls jump out from behind the trees!\n");

        int fight = rand() % 2; // Generate 0 or 1

        if(fight == 0) {
            // Player wins the fight
            printf("\nYou fight off the trolls and continue on your way.\n");
            gold += 50;
            printf("You found 50 gold!\n");
        } else {
            // Player loses the fight
            printf("\nThe trolls overpower you and take all your gold.\n");
            gold = 0;
            printf("You lost all your gold!\n");
            health -= 20;
            printf("You were hurt in the fight and lost 20 health.\n");
        }
    } else if(decision1 == 2) {
        printf("\nYou take the path on the right and continue walking.\n");
        printf("As you walk, you find a treasure chest filled with gold! You found 100 gold!\n");
        gold += 100;
    } else {
        printf("\nInvalid choice. You stumble blindly into the forest and get lost...\n");
        printf("Your adventure comes to an end.\n");
        return 0;
    }

    // Second decision and final battle
    printf("\nYou continue down the path and come to a river.\n");
    printf("There is a small boat and a bridge. Which do you choose (1 or 2)?\n");

    int decision2;
    scanf("%d", &decision2);

    // Random encounter depending on player's decision
    if(decision2 == 1) {
        printf("\nYou take the boat across the river and continue on your way.\n");
        printf("As you walk, you hear a growling noise behind you...\n");

        int fight2 = rand() % 2;

        if(fight2 == 0) {
            printf("\nYou turn around and see an angry bear charging at you!\n");

            int fight3 = rand() % 2;

            if(fight3 == 0) {
                printf("You fight the bear and emerge victorious!\n");
                gold += 100;
                printf("You found 100 gold!\n");
            } else {
                printf("You couldn't fight off the bear and got badly injured.\n");
                health -= 50;
                printf("You lost 50 health!\n");
            }
        } else {
            printf("You turn around but there's nothing there. You continue on your way.\n");
        }
    } else if(decision2 == 2) {
        printf("\nYou walk across the bridge and continue on your way.\n");
        printf("As you walk, you see a dragon up ahead blocking the path!\n");

        int fight4 = rand() % 2;

        if(fight4 == 0) {
            printf("You fight the dragon and defeat it!\n");
            gold += 500;
            printf("You found 500 gold!\n");
            items += 1;
            printf("You found a treasure map!\n");
        } else {
            printf("You couldn't fight off the dragon and got badly burnt.\n");
            health -= 50;
            printf("You lost 50 health!\n");
        }
    } else {
        printf("\nInvalid choice. You slip and fall into the water...\n");
        printf("Your adventure comes to an end.\n");
        return 0;
    }

    // Final summary of player's status
    printf("\nCongratulations! You completed the Text-Based Adventure Game.\n");
    printf("Here is your final status:\n");
    printf("Health: %d\n", health);
    printf("Gold: %d\n", gold);
    printf("Items: %d\n", items);

    return 0;
}