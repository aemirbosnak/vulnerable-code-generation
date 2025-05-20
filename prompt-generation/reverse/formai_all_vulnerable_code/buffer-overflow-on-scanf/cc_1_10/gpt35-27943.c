//FormAI DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void playGame(int);
void printRules();
int getUserChoice();
int getComputerChoice();
int determineWinner(int, int);

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    // print game rules
    printRules();
    
    // get user's choice (best of 3 or 5)
    int bestOf;
    do {
        printf("Enter '3' for best of 3 or '5' for best of 5: ");
        scanf("%d", &bestOf);
    } while (bestOf != 3 && bestOf != 5);
    
    // play the game
    playGame(bestOf);
    
    return 0;
}

void playGame(int bestOf) {
    int userScore = 0;
    int computerScore = 0;
    
    // keep playing until one player reaches the best of score
    while (userScore < (bestOf+1)/2 && computerScore < (bestOf+1)/2) {
        int userChoice = getUserChoice();
        int computerChoice = getComputerChoice();
        int result = determineWinner(userChoice, computerChoice);
        if (result == 1) {
            printf("You win!\n");
            userScore++;
        } else if (result == -1) {
            printf("Computer wins!\n");
            computerScore++;
        } else {
            printf("Tie!\n");
        }
        
        printf("Current score: You %d vs Computer %d\n\n", userScore, computerScore);
    }
    
    // print final score
    printf("Final score: You %d vs Computer %d\n", userScore, computerScore);
    if (userScore > computerScore) {
        printf("You are the game winner!\n");
    } else {
        printf("Computer is the game winner!\n");
    }
}

void printRules() {
    printf("Welcome to Rock-Paper-Scissors game!\n");
    printf("You will play against the computer.\n");
    printf("The player who wins the best of 3 or 5 games is the winner.\n");
    printf("Here are the rules:\n  Rock beats Scissors\n  Scissors beats Paper\n  Paper beats Rock\n\n");
}

int getUserChoice() {
    int choice;
    do {
        printf("Enter your choice (1=Rock, 2=Paper, 3=Scissors): ");
        scanf("%d", &choice);
    } while (choice != 1 && choice != 2 && choice != 3);
    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

int determineWinner(int userChoice, int computerChoice) {
    // 1 = user wins, -1 = computer wins, 0 = tie
    if (userChoice == 1 && computerChoice == 2) {
        return -1; // computer wins (paper beats rock)
    } else if (userChoice == 2 && computerChoice == 1) {
        return 1;  // user wins (paper beats rock)
    } else if (userChoice == 1 && computerChoice == 3) {
        return 1;  // user wins (rock beats scissors)
    } else if (userChoice == 3 && computerChoice == 1) {
        return -1; // computer wins (rock beats scissors)
    } else if (userChoice == 2 && computerChoice == 3) {
        return -1; // computer wins (scissors beats paper)
    } else if (userChoice == 3 && computerChoice == 2) {
        return 1;  // user wins (scissors beats paper)
    } else {
        return 0;  // tie
    }
}