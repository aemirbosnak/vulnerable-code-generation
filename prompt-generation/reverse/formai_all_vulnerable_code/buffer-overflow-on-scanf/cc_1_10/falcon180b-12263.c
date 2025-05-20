//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateBingoCard(char card[5][5]) {
    int i, j;
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            card[i][j] = (rand() % 10) + 1;
        }
    }
}

void printBingoCard(char card[5][5]) {
    int i, j;
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

int checkBingo(char card[5][5], int num) {
    int i, j;
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            if(card[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int i, j, num, bingo;
    char card[5][5];
    srand(time(NULL));
    generateBingoCard(card);
    printf("Your Bingo Card:\n");
    printBingoCard(card);
    while(1) {
        printf("Enter a number between 1 and 75: ");
        scanf("%d", &num);
        bingo = checkBingo(card, num);
        if(bingo == 1) {
            printf("Bingo! You win!\n");
            break;
        }
        else {
            printf("Sorry, that number is not on your card.\n");
        }
    }
    return 0;
}