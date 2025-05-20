//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int row;
    int col;
} Coordinates;

typedef struct {
    int value;
    Coordinates position;
} Card;

int main() {
    srand(time(NULL));
    int nCards = 8;
    Card* cards = (Card*) malloc(nCards * sizeof(Card));
    for (int i = 0; i < nCards; i++) {
        cards[i].value = rand() % 10;
        cards[i].position.row = rand() % 4;
        cards[i].position.col = rand() % 4;
    }
    printf("Memory game:\n");
    for (int i = 0; i < nCards; i++) {
        printf("%2d. %d at (%d, %d)\n", i+1, cards[i].value, cards[i].position.row, cards[i].position.col);
    }
    bool isOpen[nCards];
    for (int i = 0; i < nCards; i++) {
        isOpen[i] = false;
    }
    int numTurns = 0;
    while (numTurns < 2) {
        printf("\nTurn %d:\n", numTurns+1);
        for (int i = 0; i < nCards; i++) {
            if (isOpen[i]) {
                printf("   %2d. %d at (%d, %d)\n", i+1, cards[i].value, cards[i].position.row, cards[i].position.col);
            }
        }
        int guessRow, guessCol;
        printf("Guess a card's row and column: ");
        scanf("%d %d", &guessRow, &guessCol);
        int guessValue = 0;
        for (int i = 0; i < nCards; i++) {
            if (isOpen[i] && cards[i].position.row == guessRow && cards[i].position.col == guessCol) {
                guessValue = cards[i].value;
            }
        }
        if (guessValue == 0) {
            printf("No such card.\n");
        } else {
            isOpen[guessValue-1] = true;
            numTurns++;
            printf("Correct!\n");
            for (int i = 0; i < nCards; i++) {
                if (isOpen[i]) {
                    printf("   %2d. %d at (%d, %d)\n", i+1, cards[i].value, cards[i].position.row, cards[i].position.col);
                }
            }
        }
    }
    free(cards);
    return 0;
}