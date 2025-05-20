//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10 // number of cards
#define MAX_TRIES 10 // maximum number of tries
#define MAX_SCORE 20 // maximum score

void init_deck(int deck[]);
void shuffle_deck(int deck[]);
void print_deck(int deck[]);
void play_game(int deck[], int tries, int score);

int main() {
    int deck[SIZE];
    int tries = MAX_TRIES;
    int score = 0;

    init_deck(deck);
    shuffle_deck(deck);

    printf("Welcome to the Memory Game!\n");
    printf("You have %d tries to find all the pairs.\n", tries);

    play_game(deck, tries, score);

    return 0;
}

void init_deck(int deck[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        deck[i] = i + 1;
    }
}

void shuffle_deck(int deck[]) {
    int i;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        int j = rand() % SIZE;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(int deck[]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

void play_game(int deck[], int tries, int score) {
    int i, j;
    int choice1, choice2;
    int match = 0;
    int revealed_cards = 0;

    while (revealed_cards < SIZE && tries > 0) {
        printf("Revealed cards: ");
        for (i = 0; i < revealed_cards; i++) {
            printf("%d ", deck[i]);
        }
        printf("\n");
        printf("Cards left: ");
        for (i = revealed_cards; i < SIZE; i++) {
            printf("%d ", deck[i]);
        }
        printf("\n");

        printf("Enter the number of the first card: ");
        scanf("%d", &choice1);
        printf("Enter the number of the second card: ");
        scanf("%d", &choice2);

        if (choice1 == choice2) {
            printf("You chose the same card twice!\n");
        } else if (choice1 < 1 || choice1 > SIZE || choice2 < 1 || choice2 > SIZE) {
            printf("Invalid choice!\n");
        } else if (deck[choice1 - 1] == deck[choice2 - 1]) {
            printf("Match!\n");
            match = 1;
            score += 10;
        } else {
            printf("No match.\n");
            revealed_cards++;
        }
    }

    if (match) {
        printf("Congratulations! You won with a score of %d.\n", score);
    } else {
        printf("Game over. Your score is %d.\n", score);
    }
}