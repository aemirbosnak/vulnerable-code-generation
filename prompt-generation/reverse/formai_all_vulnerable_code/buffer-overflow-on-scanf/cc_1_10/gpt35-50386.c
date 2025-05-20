//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *deck, int n_cards) {
    for (int i = 0; i < n_cards; i++) {
        int r = rand() % (n_cards - i) + i;
        swap(&deck[i], &deck[r]);
    }
}

void print_deck(int *deck, int n_cards, int *revealed) {
    for (int i = 0; i < n_cards; i++) {
        if (revealed[i]) {
            printf("%d ", deck[i]);
        } else {
            printf("[] ");
        }
    }
    printf("\n");
}

int main() {
    int deck[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS / 2; i++) {
        deck[i] = i + 1;
        deck[i + NUM_CARDS / 2] = i + 1;
    }
    printf("Welcome to the Memory Game!\n");
    printf("Try to match all the pairs in the deck.\n");
    printf("Enter two numbers to reveal and compare the cards.\n");
    printf("If the cards match, they will remain revealed.\n");
    printf("If they do not match, they will be hidden again.\n");
    printf("Good luck!\n");
    shuffle(deck, NUM_CARDS);
    int revealed[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        revealed[i] = 0;
    }
    int n_revealed = 0;
    while (n_revealed < NUM_CARDS) {
        print_deck(deck, NUM_CARDS, revealed);
        int i, j;
        printf("Enter two numbers between 1 and %d: ", NUM_CARDS);
        scanf("%d %d", &i, &j);
        i--;
        j--;
        if (i < 0 || i >= NUM_CARDS || j < 0 || j >= NUM_CARDS || revealed[i] || revealed[j]) {
            printf("Invalid input or cards already revealed. Try again.\n");
            continue;
        }
        revealed[i] = 1;
        revealed[j] = 1;
        n_revealed += 2;
        if (deck[i] == deck[j]) {
            printf("Match!\n");
        } else {
            printf("No match.\n");
            revealed[i] = 0;
            revealed[j] = 0;
            n_revealed -= 2;
        }
    }
    printf("Congratulations! You matched all the cards!\n");
    return 0;
}