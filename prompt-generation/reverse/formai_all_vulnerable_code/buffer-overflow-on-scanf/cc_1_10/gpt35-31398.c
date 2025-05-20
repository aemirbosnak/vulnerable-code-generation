//FormAI DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

int main() {
    int size = 0;
    int values[MAX_SIZE];
    int guesses[MAX_SIZE];
    int i, j, temp;

    // Configuration
    printf("Enter size of memory game (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Size exceeds maximum of %d\n", MAX_SIZE);
        return 1;
    }

    // Generate random values
    srand(time(NULL));

    for (i = 0; i < size; i++) {
        values[i] = (rand() % 10) + 1;
    }

    // Shuffle values
    for (i = 0; i < size; i++) {
        j = rand() % size;
        temp = values[i];
        values[i] = values[j];
        values[j] = temp;
    }

    // Prompt for guesses
    printf("Memory game!\n");
    printf("Remember the following numbers: ");

    for (i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }

    printf("\n");

    printf("Enter your guesses (in order): ");

    for (i = 0; i < size; i++) {
        scanf("%d", &guesses[i]);
    }

    // Check guesses
    for (i = 0; i < size; i++) {
        if (guesses[i] != values[i]) {
            printf("Game over! Incorrect guess at position %d\n", i+1);
            return 1;
        }
    }

    printf("Congratulations! You win!\n");

    return 0;
}