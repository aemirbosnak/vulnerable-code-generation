//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 6

typedef struct {
    int number;
    int guess;
    int status; // 0 for incorrect, 1 for correct
} GameRecord;

void initTable(GameRecord table[][COLS]);
void printTable(GameRecord table[][COLS]);
void generateNumber(int *number);
int checkGuess(int guess, int number);
void playGame(GameRecord table[][COLS]);

int main() {
    GameRecord gameTable[ROWS][COLS];
    int number;

    srand(time(NULL));

    initTable(gameTable);
    printf("Welcome to the Number Guessing Game!\n");
    printf("I will generate a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", ROWS);

    generateNumber(&number);

    playGame(gameTable);

    printTable(gameTable);

    return 0;
}

void initTable(GameRecord table[][COLS]) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            table[i][j].number = -1;
            table[i][j].guess = 0;
            table[i][j].status = 0;
        }
    }
}

void printTable(GameRecord table[][COLS]) {
    int i, j;

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("| %-3s | %-7s | %-7s | %-7s | %-7s | %-7s |\n", "Attempt", "Guess", "Status", "Number", "Error", "Difference");
    printf("--------------------------------------------------\n");

    for (i = 0; i < ROWS; i++) {
        printf("| %-3d | %-7d | %-7s | %-7d | %-7d | %-7d |\n", i + 1, table[i][0].guess,
            table[i][0].status == 0 ? "Incorrect" : "Correct", table[i][0].number,
            table[i][0].guess > table[i][0].number ? table[i][0].guess - table[i][0].number : 0,
            abs(table[i][0].guess - table[i][0].number));
    }
    printf("--------------------------------------------------\n");
}

void generateNumber(int *number) {
    *number = rand() % 100 + 1;
}

int checkGuess(int guess, int number) {
    return guess == number;
}

void playGame(GameRecord table[][COLS]) {
    int i, guess;

    for (i = 0; i < ROWS; i++) {
        printf("Attempt %d: ", i + 1);
        scanf("%d", &guess);

        table[i][0].guess = guess;

        if (checkGuess(guess, table[i][0].number)) {
            table[i][0].status = 1;
            break;
        } else {
            printf("Incorrect! Try again.\n");
        }
    }
}