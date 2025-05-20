//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROLLS 100

void rollDice(int *history, int *count) {
    int roll = rand() % 6 + 1;
    history[*count] = roll;
    (*count)++;
    printf("You rolled a %d! What an exciting event! 🎲\n", roll);
}

void displayHistory(int *history, int count) {
    printf("\n--- Roll History ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll %d: %d\n", i + 1, history[i]);
    }
}

void displayStatistics(int *history, int count) {
    if (count == 0) {
        printf("No rolls to display statistics for!\n");
        return;
    }
    int sum = 0;
    int frequency[6] = {0}; // Tracks the frequency of each die face

    for (int i = 0; i < count; i++) {
        sum += history[i];
        frequency[history[i] - 1]++;
    }

    printf("\n--- Statistics ---\n");
    printf("Total Rolls: %d\n", count);
    printf("Sum of Rolls: %d\n", sum);
    printf("Average Roll: %.2f\n", (float)sum / count);
    
    for (int i = 0; i < 6; i++) {
        printf("Face %d: Rolled %d times.\n", i + 1, frequency[i]);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator
    int history[MAX_ROLLS];
    int rollCount = 0;
    char choice;

    printf("Welcome to the 🎲 Dice Roller! Let's roll some dice!\n");

    do {
        printf("\nPress 'r' to roll the dice, 'h' for history, 's' for statistics, or 'q' to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'r': 
                if (rollCount < MAX_ROLLS) {
                    rollDice(history, &rollCount);
                } else {
                    printf("You've reached the maximum rolls limit of %d!\n", MAX_ROLLS);
                }
                break;
            case 'h':
                displayHistory(history, rollCount);
                break;
            case 's':
                displayStatistics(history, rollCount);
                break;
            case 'q':
                printf("Thank you for playing! 🎉 Until next time!\n");
                break;
            default:
                printf("Invalid choice! Please enter 'r', 'h', 's', or 'q'.\n");
                break;
        }

    } while (choice != 'q');

    return 0;
}