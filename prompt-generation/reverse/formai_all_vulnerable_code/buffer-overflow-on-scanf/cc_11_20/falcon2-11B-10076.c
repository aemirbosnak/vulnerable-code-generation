//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK 0
#define PAPER 1
#define SCISSORS 2

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Prompt the user to input their choice
    printf("Enter your choice (rock, paper, or scissors): ");
    char choice;
    scanf("%c", &choice);

    // Convert the user's choice to a number
    int playerChoice = (choice == 'r')? ROCK : (choice == 'p')? PAPER : (choice =='s')? SCISSORS : -1;

    if (playerChoice == -1) {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    // Choose a random choice for the computer
    int computerChoice = (rand() % 3) + ROCK;

    // Compare the two choices and determine the winner
    if (playerChoice == computerChoice) {
        printf("It's a tie!\n");
    } else if (playerChoice == ROCK) {
        if (computerChoice == PAPER) {
            printf("Computer wins!\n");
        } else {
            printf("Player wins!\n");
        }
    } else if (playerChoice == PAPER) {
        if (computerChoice == SCISSORS) {
            printf("Computer wins!\n");
        } else {
            printf("Player wins!\n");
        }
    } else if (playerChoice == SCISSORS) {
        if (computerChoice == ROCK) {
            printf("Computer wins!\n");
        } else {
            printf("Player wins!\n");
        }
    } else {
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    return 0;
}