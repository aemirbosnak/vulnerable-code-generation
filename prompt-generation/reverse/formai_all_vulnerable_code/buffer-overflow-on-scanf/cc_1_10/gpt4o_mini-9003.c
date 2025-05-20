//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please think of a question you'd like the fortune teller to answer.\n");
    printf("Press Enter when you are ready to receive your fortune...\n");
    getchar(); // Wait for the user to hit Enter
}

// Function to generate a random fortune
const char* getFortune(int fortuneNumber) {
    const char* fortunes[NUM_FORTUNES] = {
        "You will find great success in your future endeavors.",
        "A surprise meeting will bring you fortune.",
        "The stars indicate a period of relaxation ahead.",
        "You will meet someone special very soon.",
        "An unexpected gift is coming your way.",
        "Hard work will pay off in ways you did not expect.",
        "Adventure awaits you; step outside your comfort zone!",
        "One of your dreams will soon become a reality.",
        "Be cautious of a friend; not everyone has your best interests at heart.",
        "The time is right to make a big decision."
    };
    return fortunes[fortuneNumber];
}

// The main function where the program starts
int main() {
    int fortuneNumber;
    char continueFortune;

    // Seed the random number generator
    srand(time(0));

    // Display instructions and wait for user to proceed
    displayInstructions();

    do {
        // Generate a random fortune number based on the defined number of fortunes
        fortuneNumber = rand() % NUM_FORTUNES;

        // Get and display the corresponding fortune
        const char* fortune = getFortune(fortuneNumber);
        printf("Your fortune: %s\n", fortune);

        // Ask user if they want to continue
        printf("Would you like to receive another fortune? (y/n): ");
        scanf(" %c", &continueFortune);
        getchar();  // Clear the newline character from input buffer

    } while (continueFortune == 'y' || continueFortune == 'Y');

    printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
    return 0;
}