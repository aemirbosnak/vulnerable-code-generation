//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: excited
#include <stdio.h> // Standard input-output library
#include <stdlib.h> // Standard library
#include <time.h> // To use time function

int main()
{
    int userScore = 0, computerScore = 0, round = 1; // Initializing scores and round number
    char userInput, computerInput; // Initializing user and computer input options

    srand(time(NULL)); // Generating random number based on the system time

    printf("\n\033[1;32mWelcome to Rock, Paper, Scissor game!\033[0m\n"); // Printing game title in green

    while(round <= 5) // Running game for 5 rounds
    {
        printf("\n\033[1;36mRound %d\033[0m\n", round); // Printing round number in cyan

        printf("Choose 'R' for Rock, 'P' for Paper, and 'S' for Scissor: "); // Prompting user to choose an option
        scanf(" %c", &userInput);

        // Generating random computer option
        int randomNum = rand() % 3;
        if(randomNum == 0) {
            computerInput = 'R';
        } else if(randomNum == 1) {
            computerInput = 'P';
        } else {
            computerInput = 'S';
        }

        // Checking user and computer's option and updating scores
        if(userInput == computerInput) {
            printf("\033[1;33mTie!\033[0m\n");
        } else if(userInput == 'R' && computerInput == 'S') {
            printf("\033[1;34mYou win!\033[0m\n");
            userScore++;
        } else if(userInput == 'P' && computerInput == 'R') {
            printf("\033[1;34mYou win!\033[0m\n");
            userScore++;
        } else if(userInput == 'S' && computerInput == 'P') {
            printf("\033[1;34mYou win!\033[0m\n");
            userScore++;
        } else {
            printf("\033[1;31mComputer wins!\033[0m\n");
            computerScore++;
        }

        round++; // Updating round number
    }

    // Printing final score and result
    printf("\n\033[1;35mFinal Score\033[0m\n");
    printf("User: %d\tComputer: %d\n", userScore, computerScore);
    if(userScore > computerScore) {
        printf("\033[1;32mCongratulations! You won the game!\033[0m\n");
    } else if(userScore == computerScore) {
        printf("\033[1;33mGame tied!\033[0m\n");
    } else {
        printf("\033[1;31mSorry! You lost the game!\033[0m\n");
    }

    return 0; // End of program
}