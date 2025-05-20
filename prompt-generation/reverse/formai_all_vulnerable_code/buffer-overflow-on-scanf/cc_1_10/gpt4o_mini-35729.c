//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FORTUNES 10

// Function Prototypes
void displayWelcomeMessage();
void displayFortune(const char *fortune);
void playAgain();

// Fortune list
const char *fortunes[MAX_FORTUNES] = {
    "You will discover a hidden talent!",
    "Adventure awaits you around the corner!",
    "An old friend will surprise you soon.",
    "You will find a dollar on the ground.",
    "Good news will come to you in the mail.",
    "You will take a journey to a faraway place.",
    "A thrilling time is in your near future.",
    "You will soon gain a new perspective on life.",
    "A financial opportunity is heading your way.",
    "Expect unexpected happiness this week!"
};

int main() {
    srand(time(NULL));  // Seed the random number generator
    displayWelcomeMessage();

    char choice;

    do {
        int fortuneIndex = rand() % MAX_FORTUNES;  // Generate a random index
        displayFortune(fortunes[fortuneIndex]);  // Display the fortune

        playAgain();  // Prompt user to play again
        printf("Do you want to see another fortune? (y/n): ");
        scanf(" %c", &choice);  // Take input from user
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the Fortune Teller! Have a wonderful day!\n");
    return 0;
}

// Function Definitions
void displayWelcomeMessage() {
    printf("*********************************\n");
    printf("*   Welcome to the Fortune      *\n");
    printf("*       Teller Program!         *\n");
    printf("*********************************\n");
    printf("Let the stars unveil your future!\n");
    printf("Press any key to get your fortune...\n");
}

void displayFortune(const char *fortune) {
    printf("Your Fortune: %s\n", fortune);
    printf("--------------------------------------------------\n");
}

void playAgain() {
    printf("--------------------------------------------------\n");
}