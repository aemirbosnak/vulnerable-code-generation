//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_NUMBERS 75

typedef struct {
    int numbers[MAX_NUMBERS];
    int count;
} Card;

void generateCard(Card* card) {
    int i;
    for (i = 0; i < MAX_NUMBERS; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
    card->count = 0;
}

void markNumber(Card* card, int number) {
    int i;
    for (i = 0; i < card->count; i++) {
        if (card->numbers[i] == number) {
            return;
        }
    }
    card->numbers[card->count++] = number;
}

int isBingo(Card* card) {
    int i, j;
    for (i = 0; i < card->count - 4; i++) {
        for (j = i + 1; j < card->count - 3; j++) {
            if (card->numbers[i] == card->numbers[j]) {
                continue;
            }
            if (card->numbers[i] / 15 == card->numbers[j] / 15) {
                continue;
            }
            if (card->numbers[i] % 15 == card->numbers[j] % 15) {
                continue;
            }
            return 0;
        }
    }
    return 1;
}

void printCard(Card* card) {
    int i;
    for (i = 0; i < card->count; i++) {
        printf("%d ", card->numbers[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Card cards[MAX_CARDS];
    int numCards, i;

    printf("How many cards do you want to generate? ");
    scanf("%d", &numCards);

    printf("Generating %d cards...\n", numCards);
    for (i = 0; i < numCards; i++) {
        generateCard(&cards[i]);
    }

    int bingoCount = 0;
    while (bingoCount < numCards) {
        int num;
        printf("Enter a number: ");
        scanf("%d", &num);
        int cardIndex = rand() % numCards;
        markNumber(&cards[cardIndex], num);
        if (isBingo(&cards[cardIndex])) {
            printf("Bingo! Card %d wins!\n", cardIndex + 1);
            printCard(&cards[cardIndex]);
            bingoCount++;
        }
    }

    return 0;
}