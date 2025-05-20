//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 16
#define MAX_ATTEMPTS 10

struct card {
    int value;
    char symbol;
};

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void shuffle(struct card *deck, int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = rand_int(0, n - 1);
        struct card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int compare_cards(struct card a, struct card b) {
    if (a.value == b.value) {
        return 0;
    } else if (a.value > b.value) {
        return 1;
    } else {
        return -1;
    }
}

void print_cards(struct card *deck, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c%d ", deck[i].symbol, deck[i].value);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct card deck[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i].value = rand_int(1, 13);
        deck[i].symbol = 'A' + i;
    }
    shuffle(deck, MAX_CARDS);
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Attempt #%d:\n", attempts + 1);
        print_cards(deck, MAX_CARDS);
        int choice1, choice2;
        printf("Choose two cards: ");
        scanf("%d %d", &choice1, &choice2);
        if (choice1 < 0 || choice1 >= MAX_CARDS || choice2 < 0 || choice2 >= MAX_CARDS) {
            printf("Invalid choice.\n");
            attempts++;
            continue;
        }
        int result = compare_cards(deck[choice1], deck[choice2]);
        if (result == 0) {
            printf("Match!\n");
        } else if (result > 0) {
            printf("Card %c%d is higher.\n", deck[choice2].symbol, deck[choice2].value);
        } else {
            printf("Card %c%d is lower.\n", deck[choice1].symbol, deck[choice1].value);
        }
        if (attempts == MAX_ATTEMPTS - 1) {
            printf("Congratulations! You win!\n");
        }
        attempts++;
    }
    return 0;
}