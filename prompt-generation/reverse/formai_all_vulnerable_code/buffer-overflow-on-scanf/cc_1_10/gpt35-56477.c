//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice and return the result
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to print the game board
void printBoard(int player1, int player2, int turn) {
    printf("\n-------------------------\n");
    for (int i = 10; i >= 1; i--) {
        printf("| ");
        if (player1 == i && player2 == i) {
            printf("P1&P2");
        } else if (player1 == i) {
            printf(" P1 ");
        } else if (player2 == i) {
            printf(" P2 ");
        } else {
            printf("    ");
        }
        if (i == 1) {
            printf("|");
        } else {
            printf(" ");
        }
        printf("\n");
    }
    printf("-------------------------\n");
    printf("Player %d's turn\n\n", turn);
}

// Function to play a turn
int playTurn(int player, int *score) {
    int roll = rollDice();
    printf("Roll: %d\n", roll);
    if (roll == 1) {
        printf("You rolled a 1 and your turn is over\n\n");
        return 0;
    } else {
        *score += roll;
        printf("Total score: %d\n\n", *score);
        return 1;
    }
}

// Function to determine if a player has won
int checkWin(int player1, int player2) {
    if (player1 >= 10 && player1 > player2) {
        return 1;
    } else if (player2 >= 10 && player2 > player1) {
        return 2;
    } else {
        return 0;
    }
}

// Main function to run the game
int main() {
    srand(time(NULL));
    int player1 = 1;
    int player2 = 1;
    int turn = 1;
    int score1 = 0;
    int score2 = 0;
    printf("Welcome to C Table Game!\n\n");
    while (1) {
        printBoard(player1, player2, turn);
        int choice;
        do {
            printf("Enter 1 to roll the dice or 2 to pass: ");
            scanf("%d", &choice);
        } while (choice != 1 && choice != 2);
        if (choice == 1) {
            if (turn == 1) {
                if (playTurn(player1, &score1) == 0) {
                    turn = 2;
                }
            } else {
                if (playTurn(player2, &score2) == 0) {
                    turn = 1;
                }
            }
        } else {
            if (turn == 1) {
                turn = 2;
            } else {
                turn = 1;
            }
        }
        player1 = score1;
        player2 = score2;
        int winner = checkWin(player1, player2);
        if (winner != 0) {
            printf("Player %d wins!\n", winner);
            break;
        }
    }
    printf("\nThank you for playing C Table Game!\n");
    return 0;
}