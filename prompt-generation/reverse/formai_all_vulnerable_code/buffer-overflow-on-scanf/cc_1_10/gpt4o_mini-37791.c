//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Array of fortunes to choose from
const char *fortunes[NUM_FORTUNES] = {
    "You will find a surprise in an unexpected location.",
    "A rainy day will bring good luck your way.",
    "Sometime next week, a new opportunity will knock.",
    "Beware of unexpected advice from a friend.",
    "You will soon receive a financial windfall.",
    "A mysterious stranger will change your life.",
    "A choice you make today will have long-term benefits.",
    "An adventure awaits you just around the corner.",
    "Trust your instincts – they are spot on.",
    "A long-lost friend will soon re-enter your life."
};

// Function to print a shocking fortune
void printShockingFortune() {
    // Generate a random number
    srand(time(NULL));
    int random_index = rand() % NUM_FORTUNES;

    // Shock! the user with their fortune!
    printf("\n======================================\n");
    printf("🔮 SHOCKING FORTUNE TELLER 🔮\n");
    printf("======================================\n\n");
    printf("Your fortune is:\n");
    printf("~~~ %s ~~~\n", fortunes[random_index]);
    printf("\n======================================\n");
}

// Main function to run the fortune teller program
int main() {
    char continue_telling;

    printf("Welcome to the Shocking Fortune Teller!\n");
    printf("Are you ready to hear your fortune? (Y/N): ");
    scanf(" %c", &continue_telling);

    // Loop to continue telling fortunes until user decides to stop
    while (continue_telling == 'Y' || continue_telling == 'y') {
        printShockingFortune();

        // Ask user if they want to hear another fortune
        printf("Would you like to hear another fortune? (Y/N): ");
        scanf(" %c", &continue_telling);
    }

    // Thank the user for participating
    printf("\nThank you for visiting the Shocking Fortune Teller! 🌟\n");
    printf("May your future be bright and full of surprises!\n");
    return 0;
}