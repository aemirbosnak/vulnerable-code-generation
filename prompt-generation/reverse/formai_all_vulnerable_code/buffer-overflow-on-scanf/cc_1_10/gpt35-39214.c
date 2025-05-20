//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Variables
int playerScore = 0;
int computerScore = 0;
int roundCount = 0;

//Function Prototypes
void displayMenu();
int rollDice();
int playRound();
void updateScore(int roundResult);

int main() {
    //Seed random number generator
    srand(time(0));

    displayMenu();

    return 0;
}

void displayMenu() {
    int input;

    printf("Welcome to C Table Game!\n\n");
    printf("1. Play Round\n");
    printf("2. View Scores\n");
    printf("3. Exit\n\n");

    printf("Please enter your choice: ");
    scanf("%d", &input);

    switch(input) {
        case 1:
            playRound();
            break;
        case 2:
            printf("\n---SCOREBOARD---\n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("-----------------\n\n");
            displayMenu();
            break;
        case 3:
            printf("Thanks for playing C Table Game!\n");
            break;
        default:
            printf("Invalid input, please try again.\n\n");
            displayMenu();
            break;
    }
}

int rollDice() {
    return (rand() % 6) + 1;
}

int playRound() {
    //Local Variables
    int playerRoll = rollDice();
    int computerRoll = rollDice();
    int roundResult = 0;

    roundCount++;
    printf("\n---ROUND %d---\n", roundCount);
    printf("You rolled: %d\n", playerRoll);
    printf("Computer rolled: %d\n", computerRoll);

    if(playerRoll > computerRoll) {
        printf("You win this round!\n\n");
        roundResult = 1;
    } else if(playerRoll < computerRoll) {
        printf("Computer wins this round!\n\n");
        roundResult = -1;
    } else {
        printf("It's a tie!\n\n");
        roundResult = 0;
    }

    updateScore(roundResult);
    displayMenu();

    return roundResult;
}

void updateScore(int roundResult) {
    if(roundResult == 1) {
        playerScore++;
    } else if(roundResult == -1) {
        computerScore++;
    }

    if(roundCount >= 5) {
        if(playerScore > computerScore) {
            printf("\n---FINAL SCORE---\n");
            printf("Congratulations, you won!\n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("-----------------\n\n");
        } else if(playerScore < computerScore) {
            printf("\n---FINAL SCORE---\n");
            printf("Sorry, you lost.\n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("-----------------\n\n");
        } else {
            printf("\n---FINAL SCORE---\n");
            printf("It's a tie!\n");
            printf("You: %d\n", playerScore);
            printf("Computer: %d\n", computerScore);
            printf("-----------------\n\n");
        }

        //Reset game
        playerScore = 0;
        computerScore = 0;
        roundCount = 0;
    }
}