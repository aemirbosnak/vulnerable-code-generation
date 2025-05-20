//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRATITUDE_MAX 10
#define GRATITUDE_MIN 1

struct gratitude {
    char name[20];
    int amount;
};

int main() {
    struct gratitude gratitudes[GRATITUDE_MAX];
    int i, j, num_gratitudes;

    // Initialize gratitudes array
    for (i = 0; i < GRATITUDE_MAX; i++) {
        gratitudes[i].name[0] = '\0';
        gratitudes[i].amount = GRATITUDE_MIN;
    }

    // Print welcome message
    printf("Welcome to the Gratitude Game!\n");

    // Print initial gratitudes
    for (i = 0; i < GRATITUDE_MAX; i++) {
        printf("Gratitude %d: %s\n", i + 1, gratitudes[i].name);
    }

    // Game loop
    while (1) {
        // Print current gratitudes and ask for input
        for (i = 0; i < GRATITUDE_MAX; i++) {
            printf("Gratitude %d: %s\n", i + 1, gratitudes[i].name);
        }
        printf("Enter a number to increase or decrease gratitude amount: ");

        // Get input from user
        scanf("%d", &j);

        // Increase or decrease gratitude amount
        if (j > 0) {
            gratitudes[j - 1].amount++;
        } else if (j < 0) {
            gratitudes[j - 1].amount--;
        }

        // Check for maximum or minimum amount
        if (gratitudes[j - 1].amount > GRATITUDE_MAX) {
            gratitudes[j - 1].amount = GRATITUDE_MAX;
        } else if (gratitudes[j - 1].amount < GRATITUDE_MIN) {
            gratitudes[j - 1].amount = GRATITUDE_MIN;
        }

        // Print updated gratitudes
        for (i = 0; i < GRATITUDE_MAX; i++) {
            printf("Gratitude %d: %s (%d)\n", i + 1, gratitudes[i].name, gratitudes[i].amount);
        }

        // Check for game over
        if (gratitudes[0].amount == GRATITUDE_MAX || gratitudes[0].amount == GRATITUDE_MIN) {
            break;
        }
    }

    // Print final gratitudes and game over message
    for (i = 0; i < GRATITUDE_MAX; i++) {
        printf("Gratitude %d: %s (%d)\n", i + 1, gratitudes[i].name, gratitudes[i].amount);
    }
    printf("Game over! Thanks for playing the Gratitude Game!\n");

    return 0;
}