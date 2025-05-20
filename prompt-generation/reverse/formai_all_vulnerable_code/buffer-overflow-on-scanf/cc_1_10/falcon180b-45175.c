//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int dice = rand() % 6 + 1;
    return dice;
}

void playGame() {
    char choice;
    int score = 0;
    int roll;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure.\n");
    printf("Are you ready to begin? (y/n) ");
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        srand(time(NULL));
        while (score < 10) {
            printf("\nYou are in a dark, mysterious forest.\n");
            printf("What would you like to do?\n");
            printf("1. Explore the forest\n");
            printf("2. Rest\n");
            printf("3. Quit\n");
            scanf("%c", &choice);
            if (choice == '1') {
                roll = rollDice();
                if (roll == 1 || roll == 2) {
                    printf("You find a hidden path!\n");
                    score++;
                } else {
                    printf("You wander aimlessly for hours.\n");
                }
            } else if (choice == '2') {
                printf("You take a nap and feel refreshed.\n");
            } else if (choice == '3') {
                printf("Thanks for playing!\n");
                exit(0);
            }
        }
        printf("\nCongratulations! You have found the legendary treasure!\n");
    } else {
        printf("Thanks for playing!\n");
    }
}

int main() {
    playGame();
    return 0;
}