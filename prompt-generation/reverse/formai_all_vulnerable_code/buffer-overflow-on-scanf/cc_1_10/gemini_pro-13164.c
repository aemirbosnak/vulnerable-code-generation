//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
    int value;
    bool revealed;
} Card;

void shuffle(Card* deck, int size) {
    for (int i = 0; i < size; i++) {
        int r = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void print_deck(Card* deck, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", deck[i].value);
    }
    printf("\n");
}

bool check_pair(Card* deck, int size, int a, int b) {
    return deck[a].value == deck[b].value;
}

int main() {
    srand(time(NULL));

    int size;
    printf("Enter the size of the deck: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size.\n");
        return 1;
    }

    Card deck[size];
    for (int i = 0; i < size; i++) {
        deck[i].value = i + 1;
        deck[i].revealed = false;
    }

    shuffle(deck, size);

    int turns = 0;
    int revealed_count = 0;
    int matched_count = 0;

    while (revealed_count < size && matched_count < size / 2) {
        int a, b;
        printf("\nEnter two indices (separated by space): ");
        scanf("%d %d", &a, &b);
        if (a < 0 || a >= size || b < 0 || b >= size) {
            printf("Invalid indices.\n");
            continue;
        }
        if (deck[a].revealed || deck[b].revealed) {
            printf("Cards already revealed.\n");
            continue;
        }

        turns++;
        deck[a].revealed = true;
        deck[b].revealed = true;

        if (check_pair(deck, size, a, b)) {
            printf("Match!\n");
            matched_count++;
        } else {
            printf("No match.\n");
            deck[a].revealed = false;
            deck[b].revealed = false;
        }

        revealed_count = 0;
        for (int i = 0; i < size; i++) {
            if (deck[i].revealed) {
                revealed_count++;
            }
        }

        print_deck(deck, size);
    }

    if (matched_count == size / 2) {
        printf("\nCongratulations! You won in %d turns.\n", turns);
    } else {
        printf("\nGame over! You lost.\n");
    }

    return 0;
}