//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_NUMBERS 24

typedef struct {
    int row;
    int col;
    int number;
} BingoCard;

void generateCard(BingoCard *card) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            card->row = i;
            card->col = j;
            card->number = rand() % MAX_NUMBERS + 1;
            printf("%d ", card->number);
        }
        printf("\n");
    }
}

int checkWin(BingoCard *card, int *numbers) {
    int rowWin = 0;
    int colWin = 0;
    int diagWin = 0;

    for (int i = 0; i < MAX_ROWS; i++) {
        if (card->row == i && numbers[card->number - 1] == 1)
            rowWin++;
    }

    for (int i = 0; i < MAX_COLS; i++) {
        if (card->col == i && numbers[card->number - 1] == 1)
            colWin++;
    }

    if (card->row == card->col) {
        if (numbers[card->number - 1] == 1)
            diagWin++;
    }

    if (rowWin == MAX_ROWS || colWin == MAX_COLS || diagWin == MAX_ROWS)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    BingoCard card;
    int numbers[MAX_NUMBERS];
    int i;

    // Initialize the numbers array
    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = 0;
    }

    // Generate the bingo card
    generateCard(&card);

    // Print the bingo card
    printf("Your bingo card:\n");
    for (i = 0; i < MAX_NUMBERS; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");

    // Mark off the numbers as they are called
    int numCalled;
    scanf("%d", &numCalled);

    for (i = 0; i < numCalled; i++) {
        scanf("%d", &numbers[i]);
        printf("%d called.\n", numbers[i]);
    }

    // Check for a win
    if (checkWin(&card, numbers)) {
        printf("Bingo! You win!\n");
    } else {
        printf("Sorry, you didn't win this time.\n");
    }

    return 0;
}