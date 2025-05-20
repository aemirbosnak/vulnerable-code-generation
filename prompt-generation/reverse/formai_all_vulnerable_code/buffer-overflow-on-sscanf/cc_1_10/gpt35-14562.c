//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_NUM_PLAYERS 10
#define MAX_SEQUENCE 50

void printFibonacciSequence(int n);
void printPlayerScores(int* scores, int numPlayers);

int main() {
    int numPlayers = 0;
    int currentPlayer = 0;
    int scores[MAX_NUM_PLAYERS] = {0};
    bool gameover = false;
    char input[10];

    printf("Welcome to Fibonacci Sequence Visualizer!\n");
    printf("Please enter the number of players (maximum 10): ");

    while (numPlayers == 0) { // loop until valid input is given
        fgets(input, 10, stdin);
        if (sscanf(input, "%d", &numPlayers) != 1 || numPlayers < 1 || numPlayers > MAX_NUM_PLAYERS) {
            printf("Invalid input. Please enter a number between 1 and %d: ", MAX_NUM_PLAYERS);
            numPlayers = 0; // reset numPlayers if input is invalid
        }
    }

    printf("\nStarting game with %d players!\n\n", numPlayers);
    printFibonacciSequence(10);

    while (!gameover) {
        printf("Player %d, please enter the next number in the sequence (enter 'quit' to end game): ", currentPlayer+1);
        fgets(input, 10, stdin);

        if (strcmp(input, "quit\n") == 0 || strcmp(input, "quit\r\n") == 0) {
            gameover = true; // end game if player enters 'quit'
        }
        else if (isdigit(input[0])) {
            int num = atoi(input);
            int nextNum = 0;
            if (currentPlayer == 0 || currentPlayer == 1) {
                nextNum = currentPlayer+1;
            }
            else {
                nextNum = scores[currentPlayer-1] + scores[currentPlayer-2];
            }

            if (num == nextNum) { // score points if input is correct
                scores[currentPlayer]++;
                printf("Correct! Player %d scores 1 point.\n", currentPlayer+1);
            }
            else {
                printf("Incorrect. The next number is %d.\n", nextNum);
            }

            if (scores[currentPlayer] == MAX_SEQUENCE) { // end game if player reaches max score
                printf("\nGame over! Player %d wins!\n", currentPlayer+1);
                gameover = true;
            }
            else {
                printPlayerScores(scores, numPlayers); // show current scores
                currentPlayer = (currentPlayer + 1) % numPlayers; // update current player
            }
        }
        else {
            printf("Invalid input. Please enter a number or 'quit'.\n");
        }
    }

    return 0;
}

void printFibonacciSequence(int n) {
    int num1 = 0, num2 = 1;
    printf("Fibonacci Sequence: %d %d ", num1, num2);
    for (int i = 2; i < n; i++) {
        int nextNum = num1 + num2;
        printf("%d ", nextNum);
        num1 = num2;
        num2 = nextNum;
    }
    printf("\n\n");
}

void printPlayerScores(int* scores, int numPlayers) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d: %d\n", i+1, scores[i]);
    }
    printf("\n");
}