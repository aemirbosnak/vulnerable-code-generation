//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define CARD_SIZE 5
#define MAX_NUMBERS 75

typedef struct {
    int numbers[CARD_SIZE][CARD_SIZE];
    bool marked[CARD_SIZE][CARD_SIZE];
} BingoCard;

void initializeCard(BingoCard *card);
void printCard(BingoCard *card);
bool checkBingo(BingoCard *card);
void drawNumber(int *drawnNumbers, int *drawCount);
void markNumber(BingoCard *card, int number);
void displayDrawnNumbers(int *drawnNumbers, int drawCount);

int main() {
    srand(time(NULL));

    BingoCard playerCard;
    initializeCard(&playerCard);
    int drawnNumbers[MAX_NUMBERS] = {0};
    int drawCount = 0;
    char input = ' ';

    printf("Welcome to the Bingo Game!\n");
    printf("Your Bingo Card:\n");
    printCard(&playerCard);

    while (1) {
        drawNumber(drawnNumbers, &drawCount);
        printf("Press 'd' to draw a number or 'q' to quit: ");
        scanf(" %c", &input);
        
        if (input == 'q') {
            printf("Thanks for playing! Your final card:\n");
            printCard(&playerCard);
            break;
        } else if (input == 'd') {
            int drawnNumber = rand() % MAX_NUMBERS + 1;
            printf("Drawn Number: %d\n", drawnNumber);
            markNumber(&playerCard, drawnNumber);
            displayDrawnNumbers(drawnNumbers, drawCount);
            if (checkBingo(&playerCard)) {
                printf("Bingo! You've got a winning card!\n");
                break;
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void initializeCard(BingoCard *card) {
    int number_set[MAX_NUMBERS] = {0};
    int count = 0;

    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            int number;
            do {
                number = rand() % (MAX_NUMBERS) + 1;
            } while (number_set[number] || (number < i * 15 + 1 || number > (i + 1) * 15));
            card->numbers[i][j] = number;
            number_set[number] = 1;
            card->marked[i][j] = false;
        }
    }
}

void printCard(BingoCard *card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->marked[i][j]) {
                printf("[X]\t");
            } else {
                printf("[%2d]\t", card->numbers[i][j]);
            }
        }
        printf("\n");
    }
}

bool checkBingo(BingoCard *card) {
    // Check rows and columns
    for (int i = 0; i < CARD_SIZE; i++) {
        if (card->marked[i][0] && card->marked[i][1] && card->marked[i][2] && card->marked[i][3] && card->marked[i][4]) {
            return true;
        }
        if (card->marked[0][i] && card->marked[1][i] && card->marked[2][i] && card->marked[3][i] && card->marked[4][i]) {
            return true;
        }
    }
    // Check diagonals
    if (card->marked[0][0] && card->marked[1][1] && card->marked[2][2] && card->marked[3][3] && card->marked[4][4]) {
        return true;
    }
    if (card->marked[0][4] && card->marked[1][3] && card->marked[2][2] && card->marked[3][1] && card->marked[4][0]) {
        return true;
    }

    return false;
}

void drawNumber(int *drawnNumbers, int *drawCount) {
    // Drawing the number is handled in the main loop
}

void markNumber(BingoCard *card, int number) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card->numbers[i][j] == number) {
                card->marked[i][j] = true;
                printf("Marked %d on your card.\n", number);
            }
        }
    }
}

void displayDrawnNumbers(int *drawnNumbers, int drawCount) {
    printf("Drawn Numbers: ");
    for (int i = 0; i < drawCount; i++) {
        printf("%d ", drawnNumbers[i]);
    }
    printf("\n");
}