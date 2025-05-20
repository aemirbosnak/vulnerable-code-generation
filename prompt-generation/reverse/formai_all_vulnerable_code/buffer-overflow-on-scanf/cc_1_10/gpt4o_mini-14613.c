//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMessage(int roll) {
    switch (roll) {
        case 1:
            printf("🎲 You rolled a ONE! That's a start!\n");
            break;
        case 2:
            printf("🎲 You rolled a TWO! Nice, let's keep it going!\n");
            break;
        case 3:
            printf("🎲 You've got a THREE! A perfect middle ground!\n");
            break;
        case 4:
            printf("🎲 You rolled a FOUR! Awesome roll!\n");
            break;
        case 5:
            printf("🎲 You rolled a FIVE! You're on fire!\n");
            break;
        case 6:
            printf("🎲 You rolled a SIX! Congratulations, that's the highest!\n");
            break;
        default:
            printf("Error: Invalid Roll!\n");
            break;
    }
}

void rollDice() {
    int roll = (rand() % 6) + 1; // generate a number between 1 and 6
    printMessage(roll);
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int choice;

    printf("🎉 Welcome to the Exciting Dice Roller! 🎉\n");
    printf("Enter how many times you want to roll the dice (1 to 10): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 10) {
        printf("🚫 Invalid number of rolls! Please try again!\n");
        return 1;
    }

    printf("🎲 Let's roll the dice %d times! 🎲\n", choice);
    
    for (int i = 0; i < choice; i++) {
        printf("Rolling... ");
        rollDice();
        printf("Press Enter to roll again...\n");
        getchar(); // consume newline left in buffer
        getchar(); // wait for Enter
    }

    printf("🎊 Thanks for playing the Dice Roller! 🎊\n");
    return 0;
}