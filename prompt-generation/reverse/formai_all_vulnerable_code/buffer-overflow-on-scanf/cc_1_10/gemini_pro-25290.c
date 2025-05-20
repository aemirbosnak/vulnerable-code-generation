//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random fortune
char *generate_fortune() {
    // Array of possible fortunes
    char *fortunes[] = {
        "You will have a great day today.",
        "You will meet someone new and exciting.",
        "You will get a promotion at work.",
        "You will win the lottery.",
        "You will find love.",
        "You will travel to a new country.",
        "You will have a baby.",
        "You will get married.",
        "You will live a long and happy life.",
        "You will die a horrible death."
    };

    // Generate a random number between 0 and 9
    int index = rand_range(0, 9);

    // Return the fortune at the index
    return fortunes[index];
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Generate a fortune for the user
    char *fortune = generate_fortune();

    // Print the fortune to the user
    printf("Your fortune is: %s\n", fortune);

    return 0;
}