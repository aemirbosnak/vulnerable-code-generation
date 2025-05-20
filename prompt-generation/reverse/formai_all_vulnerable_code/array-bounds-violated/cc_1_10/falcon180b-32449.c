//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct bingoCard {
    int numbers[25];
    int win[5];
};

void printBingoCard(struct bingoCard card) {
    printf("Bingo Card:\n");
    for (int i = 0; i < 5; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d ", card.numbers[i * 5 + j]);
        }
        printf("\n");
    }
}

void generateBingoCard(struct bingoCard* card) {
    srand(time(0));
    for (int i = 0; i < 25; i++) {
        card->numbers[i] = rand() % 75 + 1;
    }
}

int checkWin(struct bingoCard card) {
    int winCount = 0;
    for (int i = 0; i < 5; i++) {
        if (card.win[i] == 1) {
            winCount++;
        }
    }
    return winCount;
}

int main() {
    struct bingoCard card;
    generateBingoCard(&card);
    printBingoCard(card);

    int playerCount = 1;
    while (playerCount <= 5) {
        int number;
        printf("Enter a number between 1 and 75: ");
        scanf("%d", &number);
        if (number > 0 && number <= 75) {
            int row = number / 15;
            int col = number % 15;
            if (card.numbers[row * 5 + col] == number) {
                card.win[row] = 1;
                printBingoCard(card);
                if (checkWin(card) == 5) {
                    printf("Congratulations! You won!\n");
                    break;
                }
            } else {
                printf("Sorry, that number is not on your card.\n");
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
        playerCount++;
    }

    return 0;
}