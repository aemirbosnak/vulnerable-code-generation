//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCARDS 16
#define NGUESSES 10

char cards[NCARDS] = {
    'A', '2', '3', '4', '5', '6', '7', '8',
    '9', 'T', 'J', 'Q', 'K', 'A', '2', '3'
};

int main() {
    int i, j, k, l, m, n;
    int guesses = NGUESSES;
    int found = 0;
    char c, d;

    srand(time(NULL));

    for (i = 0; i < NCARDS; i++) {
        j = rand() % NCARDS;
        k = cards[i];
        cards[i] = cards[j];
        cards[j] = k;
    }

    while (guesses > 0 && !found) {
        printf("Guesses left: %d\n", guesses);
        printf("Cards: ");
        for (i = 0; i < NCARDS; i++) {
            printf("%c ", cards[i]);
        }
        printf("\n");

        printf("Enter two cards to flip: ");
        scanf("%c %c", &c, &d);

        for (i = 0; i < NCARDS; i++) {
            if (cards[i] == c) {
                j = i;
            }
            if (cards[i] == d) {
                k = i;
            }
        }

        if (cards[j] == cards[k]) {
            printf("Match!\n");
            cards[j] = ' ';
            cards[k] = ' ';
            found++;
        } else {
            printf("No match.\n");
            guesses--;
        }
    }

    if (found == NCARDS / 2) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }

    return 0;
}