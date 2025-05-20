//Falcon-180B DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
int playerScore = 0;
int computerScore = 0;
int gameOver = 0;

// Function Prototypes
void startGame();
void playRound();
int getRandomNumber();
int getPlayerChoice();
int getComputerChoice();
void determineWinner(int playerChoice, int computerChoice);

int main() {
    srand(time(NULL));
    startGame();
    return 0;
}

void startGame() {
    int choice;

    do {
        system("clear");
        printf("Welcome to Rock Paper Scissors!\n");
        printf("Please choose an option:\n");
        printf("1. Play Game\n");
        printf("2. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                playRound();
                break;
            case 2:
                gameOver = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(gameOver == 0);
}

void playRound() {
    int playerChoice, computerChoice;

    playerChoice = getPlayerChoice();
    computerChoice = getComputerChoice();

    determineWinner(playerChoice, computerChoice);

    if(gameOver == 0) {
        playRound();
    }
}

int getRandomNumber() {
    return rand() % 3;
}

int getPlayerChoice() {
    int choice;

    do {
        system("clear");
        printf("Rock Paper Scissors!\n");
        printf("Please choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            case 2:
            case 3:
                return choice;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(1);
}

int getComputerChoice() {
    return getRandomNumber();
}

void determineWinner(int playerChoice, int computerChoice) {
    if(playerChoice == computerChoice) {
        printf("Tie!\n");
    } else if((playerChoice == 1 && computerChoice == 2) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2) ||
               (playerChoice == 2 && computerChoice == 3)) {
        printf("You win this round!\n");
        playerScore++;
    } else {
        printf("Computer wins this round!\n");
        computerScore++;
    }

    printf("Score: You - %d, Computer - %d\n", playerScore, computerScore);

    if(playerScore >= 5 || computerScore >= 5) {
        gameOver = 1;
    }
}