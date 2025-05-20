//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

void printFortune(int fortuneIndex);
void displayInstructions();

int main() {
    int userChoice;
    
    // Initialize random number generator
    srand(time(NULL));

    // Display instructions to the user
    displayInstructions();

    // Get user's choice
    printf("Please enter a number between 1 and 5 to receive your fortune or 0 to exit: ");
    while (1) {
        scanf("%d", &userChoice);

        // Check for exit condition
        if (userChoice == 0) {
            printf("Thank you for using the fortune teller. Goodbye!\n");
            break;
        } else if (userChoice < 1 || userChoice > 5) {
            printf("Invalid choice! Please enter a number between 1 and 5 or 0 to exit: ");
            continue;
        }

        // Generate a random fortune
        int fortuneIndex = rand() % NUM_FORTUNES;
        printFortune(fortuneIndex);
        printf("Please enter a number between 1 and 5 to receive your fortune or 0 to exit: ");
    }

    return 0;
}

void printFortune(int fortuneIndex) {
    const char *fortunes[NUM_FORTUNES] = {
        "You will find a new path in your life soon.",
        "A great opportunity is just around the corner.",
        "Love is on its way, stay open to new connections.",
        "A financial surprise is coming your way.",
        "A long-lost friend will soon reach out to you.",
        "Patience is key; everything will work out in time.",
        "You will make a significant discovery about yourself.",
        "Travel is on the horizon; pack your bags!",
        "Expect a challenge that will make you stronger.",
        "Be open to advice from an unexpected source."
    };

    printf("Your fortune: %s\n", fortunes[fortuneIndex]);
}

void displayInstructions() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("This program will provide you with random fortunes based on your input.\n");
    printf("You can choose a number between 1 and 5 to receive your fortune, or enter 0 to exit.\n");
    printf("Let's see what the future holds for you!\n");
}