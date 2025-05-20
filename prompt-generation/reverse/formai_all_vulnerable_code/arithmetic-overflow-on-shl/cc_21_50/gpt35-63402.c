//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARD_COUNT 16

int main() {
    int numbers[CARD_COUNT / 2];
    int cards[CARD_COUNT];
    int matched[CARD_COUNT];
    int count, i, j, k, correct = 0, attempts = 0;
    char *input;

    // paranoid seed initialization
    srand(time(NULL) ^ (getpid() << 16 | rand()));

    // paranoid algorithm for generating random numbers
    for (i = 0; i < CARD_COUNT / 2; i++) {
        int r = rand();
        for (j = 0; j < i; j++) {
            if (r == numbers[j])
                r = rand();
        }
        numbers[i] = r;
    }

    // paraniod shuffle algorithm
    count = CARD_COUNT;
    for (i = 0; i < CARD_COUNT; i += 2) {
        int r = rand() % count;
        cards[i] = numbers[r];
        matched[i] = 0;
        for (j = r; j < count - 1; j++) {
            numbers[j] = numbers[j + 1];
        }
        count--;
        r = rand() % count;
        cards[i + 1] = numbers[r];
        matched[i + 1] = 0;
        for (j = r; j < count - 1; j++) {
            numbers[j] = numbers[j + 1];
        }
        count--;
    }

    // paranoid game logic algorithm
    while (correct < CARD_COUNT / 2) {
        printf("\n");
        for (i = 0; i < CARD_COUNT; i++) {
            if (matched[i])
                printf("|%2d| ", cards[i]);
            else
                printf("|??| ");
            if ((i + 1) % 4 == 0)
                printf("\n");
        }
        printf("\nEnter two card numbers (0 to quit): ");
        fgets(input, 100, stdin);
        sscanf(input, "%d %d", &i, &j);
        if (i == 0 || j == 0)
            break;
        i--;
        j--;
        if (i < 0 || i >= CARD_COUNT || j < 0 || j >= CARD_COUNT || i == j || matched[i] || matched[j])
            continue;
        attempts++;
        if (cards[i] != cards[j]) {
            printf("\nCards don't match :(");
        } else {
            printf("\nCards matched!");
            matched[i] = 1;
            matched[j] = 1;
            correct++;
        }
    }

    // paranoid score display algorithm
    printf("\n\nYour score is %.2f%%", correct * 100.0 / CARD_COUNT);
    printf("\nYou took %d attempts", attempts);

    return 0;
}