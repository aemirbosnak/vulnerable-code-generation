//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_SCORE 50

void welcome();
void initializeScores(int scores[], int players);
void printScores(int scores[], int players);
int rollDice();
int playRound(int player);
int checkWinner(int scores[], int players);

int main() {
    int scores[MAX_PLAYERS];
    int players, turn = 0;
    int winner = -1;

    welcome();
   
    printf("Enter the number of players (2 to %d): ", MAX_PLAYERS);
    scanf("%d", &players);
    if (players < 2 || players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    initializeScores(scores, players);

    while (winner == -1) {
        printf("\n--- Player %d's Turn ---\n", (turn % players) + 1);
        int points = playRound(turn % players);
        scores[turn % players] += points;

        printScores(scores, players);
        winner = checkWinner(scores, players);

        turn++;
    }

    printf("\nCongratulations! Player %d wins with %d points!\n", winner + 1, scores[winner]);
    return 0;
}

void welcome() {
    printf("Welcome to the Dice Rolling Game!\n");
    printf("Reach %d points to win.\n", MAX_SCORE);
}

void initializeScores(int scores[], int players) {
    for (int i = 0; i < players; i++) {
        scores[i] = 0;
    }
}

void printScores(int scores[], int players) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < players; i++) {
        printf("Player %d: %d points\n", i + 1, scores[i]);
    }
}

int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1); // Roll two dice
}

int playRound(int player) {
    int points = 0;
    char choice;

    do {
        int roll = rollDice();
        printf("Player %d rolls: %d\n", player + 1, roll);

        if (roll == 7) {
            printf("Lucky 7! You gain 10 extra points!\n");
            points += 10;
        } else if (roll == 2 || roll == 12) {
            printf("Craps! You lose 5 points!\n");
            points -= 5;
        } else if (roll % 2 == 0) {
            printf("Even roll! You gain 5 points.\n");
            points += 5;
        } else {
            printf("Odd roll! You gain nothing this round.\n");
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return points > 0 ? points : 0; // Ensure not to return negative points
}

int checkWinner(int scores[], int players) {
    for (int i = 0; i < players; i++) {
        if (scores[i] >= MAX_SCORE) {
            return i;
        }
    }
    return -1;
}