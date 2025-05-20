//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void shuffle(int *deck, int size);
void print_deck(int *deck, int size);
void play(int *deck, int size);

int main() {
    int deck[SIZE];
    int i;
    srand(time(0));
    for (i = 0; i < SIZE; i++) {
        deck[i] = i + 1;
    }
    shuffle(deck, SIZE);
    play(deck, SIZE);
    return 0;
}

void shuffle(int *deck, int size) {
    int i, j, temp;
    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(int *deck, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

void play(int *deck, int size) {
    int i, j, choice, match, tries = 0;
    printf("Welcome to Memory Game!\n");
    printf("The deck has %d cards.\n", size);
    for (i = 0; i < size; i++) {
        match = 0;
        while (!match) {
            choice = rand() % size;
            if (choice!= i) {
                match = 1;
            }
        }
        deck[i] = choice;
        deck[choice] = i;
    }
    printf("Shuffling the deck...\n");
    shuffle(deck, size);
    print_deck(deck, size);
    while (1) {
        printf("Your turn. Choose two cards:\n");
        scanf("%d %d", &i, &j);
        if (deck[i] == deck[j]) {
            printf("Match! Try again.\n");
            tries++;
        } else {
            printf("Mismatch. Try again.\n");
        }
        if (tries == 5) {
            printf("Game over. You lose.\n");
            break;
        }
    }
}