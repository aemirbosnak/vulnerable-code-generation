//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void welcomeUser() {
    printf("Welcome to the Ultimate Dice Roller!\n");
    printf("Are you ready to roll some dice? (yes/no)\n");
}

int getUserResponse() {
    char response[10];
    scanf("%s", response);

    if (strcmp(response, "yes") == 0) {
        return 1; // Yes
    } else {
        return 0; // No
    }
}

void promptUserForDieCount() {
    printf("How many dice would you like to roll? (1-10)\n");
}

int getDieCount() {
    int count;
    while (1) {
        scanf("%d", &count);
        if (count >= 1 && count <= 10) {
            return count;
        } else {
            printf("Hmm, that's not a valid number of dice. Please enter a number from 1 to 10:\n");
        }
    }
}

void rollDice(int count) {
    printf("Here's what you rolled:\n");
    for (int i = 0; i < count; i++) {
        int roll = (rand() % 6) + 1; // Rolls a die (1-6)
        printf("Die %d: %d\n", i + 1, roll);
    }
}

void askAboutReRoll() {
    printf("Would you like to roll again? (yes/no)\n");
}

int main() {
    srand(time(0)); // Seed the random number generator

    welcomeUser();
    
    if (!getUserResponse()) {
        printf("Ah, that's too bad! Until next time then!\n");
        return 0;
    }

    while (1) {
        promptUserForDieCount();
        int dieCount = getDieCount();

        rollDice(dieCount);

        askAboutReRoll();
        if (!getUserResponse()) {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }
    }
    
    return 0;
}