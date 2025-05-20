//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 100
#define MAX_PLAYERS 10
#define MAX_CARDS 5

typedef struct {
    int numbers[MAX_NUMBERS];
    int num_called;
    int num_players;
} BingoGame;

void shuffle(int numbers[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    int players = 0;
    int num_cards = 0;

    printf("Welcome to Bingo Simulator!\n");
    printf("How many players are there? (Max %d): ", MAX_PLAYERS);
    scanf("%d", &players);

    if (players > MAX_PLAYERS) {
        printf("Too many players! Please try again.\n");
        return 1;
    }

    printf("How many cards do you want to play with? (Max %d): ", MAX_CARDS);
    scanf("%d", &num_cards);

    if (num_cards > MAX_CARDS) {
        printf("Too many cards! Please try again.\n");
        return 1;
    }

    int cards[MAX_CARDS][5][5];
    int numbers[MAX_NUMBERS];
    int num_called = 0;

    printf("Generating cards...\n");
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cards[i][j][k] = rand() % 100;
            }
        }
    }

    printf("Your cards:\n");
    for (int i = 0; i < num_cards; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                printf("%d ", cards[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    int bingo = 0;

    while (!bingo) {
        int num = rand() % 100;
        if (num == 0) {
            printf("Bingo! Player %d wins!\n", 0);
            bingo = 1;
        } else if (num_called == 0) {
            printf("First number: %d\n", num);
        } else {
            printf("Next number: %d\n", num);
        }

        numbers[num_called] = num;
        num_called++;

        if (num_called == 5) {
            printf("No more numbers to call. Game over.\n");
            break;
        }
    }

    return 0;
}