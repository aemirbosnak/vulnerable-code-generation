//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void play();
void endgame(int score);

int main() {
    srand(time(0));
    int choice;
    int score = 0;

    intro();

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Play the game\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            play();
            score += rand() % 11;
        }
        else if(choice == 2) {
            endgame(score);
            break;
        }
        else {
            printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}

void intro() {
    printf("\nWelcome to the Surprised Adventure!\n");
    printf("You are about to embark on a journey full of surprises.\n");
    printf("Are you ready? (y/n)\n");

    char answer;
    scanf(" %c", &answer);

    if(answer!= 'y') {
        printf("Exiting program...\n");
        exit(0);
    }
}

void play() {
    int choice;

    printf("\nYou find yourself in a dark room.\n");
    printf("There are three doors in front of you.\n");
    printf("Which door do you choose?\n");
    printf("1. Door 1\n");
    printf("2. Door 2\n");
    printf("3. Door 3\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nYou open Door 1 and find a treasure chest!\n");
            printf("You gain 5 points.\n");
            break;
        case 2:
            printf("\nYou open Door 2 and find a monster!\n");
            printf("You lose 3 points.\n");
            break;
        case 3:
            printf("\nYou open Door 3 and find a magical portal!\n");
            printf("You gain 7 points.\n");
            break;
        default:
            printf("\nInvalid choice, try again.\n");
            break;
    }
}

void endgame(int score) {
    if(score > 0) {
        printf("\nCongratulations! You have won the game with a score of %d.\n", score);
    }
    else if(score < 0) {
        printf("\nSorry, you have lost the game with a score of %d.\n", score);
    }
    else {
        printf("\nYou have tied the game with a score of 0.\n");
    }
}