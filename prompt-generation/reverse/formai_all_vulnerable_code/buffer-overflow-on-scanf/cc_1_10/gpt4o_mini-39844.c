//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FORTUNES 10

// Function to generate random fortunes
char* getFortune(int index) {
    char* fortunes[NUM_FORTUNES] = {
        "You will find a new opportunity in your career.",
        "A surprising encounter will bring you joy.",
        "Trust your instincts, they will guide you well.",
        "An adventure awaits you, embrace the journey.",
        "A financial gain is in your near future.",
        "Your creativity will lead to unexpected places.",
        "A close friend will need your support soon.",
        "You will discover a hidden talent within yourself.",
        "Change is coming, and it will be for the better.",
        "Love is around the corner, keep your heart open."
    };
    return fortunes[index];
}

// Function to print the welcome message
void printWelcomeMessage() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Let me predict your future with a unique fortune.\n");
    printf("Press Enter to receive your fortune!\n");
}

// Function to pause the program
void pauseProgram() {
    printf("Press Enter to continue...\n");
    getchar();
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Welcome message
    printWelcomeMessage();

    // Wait for user input
    getchar();

    // Generate a random index for the fortune
    int randomIndex = rand() % NUM_FORTUNES;

    // Retrieve and print the fortune
    printf("Your fortune: \"%s\"\n", getFortune(randomIndex));

    // Repeat the fortune telling or exit option
    char repeat;
    do {
        printf("Would you like to know another fortune? (y/n): ");
        scanf(" %c", &repeat);
        getchar(); // clear the newline character from the input buffer

        if (repeat == 'y' || repeat == 'Y') {
            randomIndex = rand() % NUM_FORTUNES;
            printf("Your fortune: \"%s\"\n", getFortune(randomIndex));
            pauseProgram();
        } else if (repeat == 'n' || repeat == 'N') {
            printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}