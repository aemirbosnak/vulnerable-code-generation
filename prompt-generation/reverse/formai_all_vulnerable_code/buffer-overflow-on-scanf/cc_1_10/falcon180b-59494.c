//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_bingo_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            card[i][j] = rand() % 15 + 1;
        }
    }
}

void print_bingo_card(int card[5][5]) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", card[i][j]);
        }
        printf("\n");
    }
}

void play_bingo(int card[5][5], int numbers[75]) {
    int i, j, k, count = 0;
    for (k = 0; k < 75; k++) {
        i = rand() % 5;
        j = rand() % 5;
        if (card[i][j] == numbers[k]) {
            count++;
        }
        if (count == 5) {
            printf("Bingo!\n");
            exit(0);
        }
    }
}

int main() {
    int card[5][5], numbers[75];
    srand(time(NULL));
    generate_bingo_card(card);
    print_bingo_card(card);
    printf("Enter 75 numbers separated by spaces:\n");
    for (int i = 0; i < 75; i++) {
        scanf("%d", &numbers[i]);
    }
    play_bingo(card, numbers);
    return 0;
}