//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random fortune
char *randomFortune() {
    // Array of possible fortunes
    char *fortunes[] = {
        "You will have a great day today.",
        "You will meet someone new and exciting.",
        "You will receive a gift from a loved one.",
        "You will have a financial windfall.",
        "You will find your true love.",
        "You will have a successful career.",
        "You will live a long and happy life.",
        "You will be a great parent.",
        "You will be a successful artist.",
        "You will be a famous athlete.",
        "You will be a world leader.",
        "You will be a billionaire.",
        "You will find the meaning of life.",
        "You will achieve your dreams.",
        "You will be happy and content.",
        "You will be loved and cherished.",
        "You will make a difference in the world.",
        "You will be remembered for your kindness.",
        "You will be an inspiration to others."
    };

    // Get a random index
    int index = randomNumber(0, 19);

    // Return the fortune at the random index
    return fortunes[index];
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random fortune
    char *fortune = randomFortune();

    // Print the fortune to the console
    printf("%s\n", fortune);

    return 0;
}