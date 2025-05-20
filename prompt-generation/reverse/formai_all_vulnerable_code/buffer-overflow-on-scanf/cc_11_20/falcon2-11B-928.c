//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char player1Choice[10];
    char player2Choice[10];
    char computerChoice[10];
    int player1Score = 0;
    int player2Score = 0;

    // Get player 1's choice
    printf("Player 1, choose your move (rock, paper, or scissors): ");
    scanf("%s", player1Choice);

    // Get player 2's choice
    printf("Player 2, choose your move (rock, paper, or scissors): ");
    scanf("%s", player2Choice);

    // Randomly generate computer's choice
    srand(time(NULL));
    int randomNumber = rand() % 3;
    if (randomNumber == 0)
        strcpy(computerChoice, "rock");
    else if (randomNumber == 1)
        strcpy(computerChoice, "paper");
    else
        strcpy(computerChoice, "scissors");

    // Determine the winner
    if (strcmp(player1Choice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0)
        printf("Player 1 wins!\n");
    else if (strcmp(player1Choice, "paper") == 0 && strcmp(computerChoice, "rock") == 0)
        printf("Player 1 wins!\n");
    else if (strcmp(player1Choice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0)
        printf("Player 1 wins!\n");
    else if (strcmp(player2Choice, "rock") == 0 && strcmp(computerChoice, "scissors") == 0)
        printf("Player 2 wins!\n");
    else if (strcmp(player2Choice, "paper") == 0 && strcmp(computerChoice, "rock") == 0)
        printf("Player 2 wins!\n");
    else if (strcmp(player2Choice, "scissors") == 0 && strcmp(computerChoice, "paper") == 0)
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");

    printf("Player 1's score: %d\n", player1Score);
    printf("Player 2's score: %d\n", player2Score);

    return 0;
}