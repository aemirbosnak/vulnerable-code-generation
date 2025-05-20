//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 5
#define TOTAL_CARDS (ROWS * COLS)
#define MATCH_SCORE 10
#define UNMATCH_PENALTY 1
#define MAX_TRIES 3

int deck[TOTAL_CARDS];
int matches = 0;
int tries = 0;

void init_deck() {
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) {
        deck[i] = i + 1;
    }
}

void shuffle_deck() {
    srand(time(NULL));
    int i, j, temp;
    for (i = 0; i < TOTAL_CARDS; i++) {
        j = rand() % TOTAL_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck() {
    int i;
    for (i = 0; i < TOTAL_CARDS; i++) {
        printf("%d ", deck[i]);
    }
    printf("\n");
}

int check_match(int card1, int card2) {
    if (card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

void play_game() {
    init_deck();
    shuffle_deck();
    print_deck();
    int choice1, choice2, match_found = 0;
    while (match_found < TOTAL_CARDS && tries < MAX_TRIES) {
        printf("Enter first card: ");
        scanf("%d", &choice1);
        printf("Enter second card: ");
        scanf("%d", &choice2);
        if (check_match(choice1, choice2)) {
            printf("Match found!\n");
            match_found += 2;
        } else {
            printf("No match found.\n");
            tries++;
        }
    }
    if (match_found == TOTAL_CARDS) {
        printf("You win!\n");
    } else {
        printf("You lose.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Play game\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            play_game();
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}