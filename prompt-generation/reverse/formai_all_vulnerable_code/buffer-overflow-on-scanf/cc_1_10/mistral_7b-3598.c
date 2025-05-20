//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct MysteryBox {
    int array[SIZE];
    int hidden;
} MysteryBox;

void mystery_box_create(MysteryBox *box) {
    int i;
    for (i = 0; i < SIZE; i++) {
        box->array[i] = rand() % 100;
    }
    box->hidden = rand() % 100;
}

void mystery_box_solve(const MysteryBox *box, int guess) {
    int i;
    int difference;

    printf("\nSherlock, the box contains: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", box->array[i]);
    }

    difference = abs(guess - box->hidden);

    if (difference < 10) {
        printf("\nBravo, Sherlock! You've found the hidden number: %d", box->hidden);
    } else {
        printf("\nTry again, dear Sherlock. The difference between your guess and the hidden number is too large.");
    }
}

int main() {
    MysteryBox box;
    int guess;

    mystery_box_create(&box);
    printf("\nThe hidden number in the box is: ");
    mystery_box_solve(&box, 55);

    printf("\nEnter your guess: ");
    scanf("%d", &guess);

    mystery_box_solve(&box, guess);

    return 0;
}