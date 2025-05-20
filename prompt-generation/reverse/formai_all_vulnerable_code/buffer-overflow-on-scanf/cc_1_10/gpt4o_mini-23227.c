//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayGratitude(int roll, int sides) {
    if (roll == sides) {
        printf("You rolled a big %d! What a lucky day to be rolling high! 🎉\n", roll);
    } else if (roll == 1) {
        printf("You rolled a humble %d. Sometimes, the simplest moments bring the greatest joy.\n", roll);
    } else {
        printf("You rolled a wonderful %d! Each roll is a gift, no matter the number!\n", roll);
    }
}

void welcomeMessage() {
    printf("Welcome to the Grateful Dice Roller!\n");
    printf("Here, we celebrate every roll! Let's find out what fate has in store for you.\n");
    printf("Remember, every result is a blessing in disguise.\n\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Roll the dice
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int sides;
    char choice;

    welcomeMessage();

    do {
        printf("How many sides should the dice have? (Enter a number greater than 1): ");
        while (scanf("%d", &sides) != 1 || sides <= 1) {
            printf("Please enter a valid number greater than 1: ");
            while(getchar() != '\n'); // Clear input buffer
        }
        
        int roll = rollDice(sides);
        displayGratitude(roll, sides);

        printf("\nWould you like to roll again? (y/n): ");
        while (getchar() != '\n'); // Clear input buffer
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for playing the Grateful Dice Roller!\n");
    printf("May the spirit of gratitude accompany you on your journey! 🌟\n");

    return 0;
}