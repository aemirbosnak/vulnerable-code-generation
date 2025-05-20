//FormAI DATASET v1.0 Category: Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYER_NAME 20
#define MAX_ROUND 5

void clearScreen() {
    system("clear");
}

void printHeader() {
    printf("*******************************************\n");
    printf("           ROCK-PAPER-SCISSORS GAME           \n");
    printf("*******************************************\n");
}

void printMenu() {
    printf("\n\nMAIN MENU\n");
    printf("1. Play Game\n");
    printf("2. Rules\n");
    printf("3. Exit\n");
}

void printRules() {
    printf("RULES\n");
    printf("- You will play against the computer.\n");
    printf("- You will have to choose either rock, paper, or scissors.\n");
    printf("- Rock beats scissors, paper beats rock, scissors beats paper.\n");
    printf("- There will be 5 rounds.\n");
    printf("- The one who wins the most rounds will win the game.\n");
}

int getPlayerChoice() {
    int choice;
    printf("\n\nPlease choose your weapon:\n");
    printf("1. Rock\n");
    printf("2. Paper\n");
    printf("3. Scissors\n");
    scanf("%d", &choice);
    return choice;
}

int getComputerChoice() {
    return rand() % 3 + 1;
}

void printChoice(int choice, char playerName[MAX_PLAYER_NAME]) {
    printf("%s choose: ", playerName);
    switch (choice) {
        case 1:
            printf("ROCK\n");
            break;
        case 2:
            printf("PAPER\n");
            break;
        case 3:
            printf("SCISSORS\n");
            break;
        default:
            printf("INVALID CHOICE\n");
            break;
    }
}

void printWin(char playerName[MAX_PLAYER_NAME]) {
    printf("%s wins!\n", playerName);
}

void printTie() {
    printf("It's a tie!\n");
}

void printScore(int playerScore, int computerScore) {
    printf("Player Score: %d, Computer Score: %d\n", playerScore, computerScore);
}

int determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return 0;
    } else {
        if (playerChoice == 1 && computerChoice == 3) {
            return 1;
        } else if (playerChoice == 2 && computerChoice == 1) {
            return 1;
        } else if (playerChoice == 3 && computerChoice == 2) {
            return 1;
        } else {
            return 2;
        }
    }
}

void playGame(char playerName[MAX_PLAYER_NAME]) {
    int playerScore = 0;
    int computerScore = 0;
    int roundCount = 1;
    int playerChoice, computerChoice, winner;

    while (roundCount <= MAX_ROUND) {
        clearScreen();
        printHeader();
        printf("\n\nROUND %d\n", roundCount);
        printScore(playerScore, computerScore);
        playerChoice = getPlayerChoice();
        computerChoice = getComputerChoice();
        printChoice(playerChoice, playerName);
        printChoice(computerChoice, "Computer");

        winner = determineWinner(playerChoice, computerChoice);
        if (winner == 1) {
            playerScore++;
            printWin(playerName);
        } else if (winner == 2) {
            computerScore++;
            printWin("Computer");
        } else {
            printTie();
        }

        roundCount++;
        printf("Press Enter to Continue\n");
        fflush(stdin);
        getchar();
    }

    clearScreen();
    printHeader();
    printScore(playerScore, computerScore);

    if (playerScore > computerScore) {
        printWin(playerName);
    } else if (playerScore < computerScore) {
        printWin("Computer");
    } else {
        printTie();
    }
}

int main() {
    srand(time(NULL));
    char playerName[MAX_PLAYER_NAME];
    int choice;

    printHeader();

    printf("\n\nPlease enter your name: ");
    scanf("%s", playerName);

    do {
        clearScreen();
        printHeader();
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame(playerName);
                break;
            case 2:
                clearScreen();
                printHeader();
                printRules();
                printf("Press Enter to Continue\n");
                fflush(stdin);
                getchar();
                break;
            case 3:
                printf("\nThank you for playing!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }

    } while (choice != 3);

    return 0;
}