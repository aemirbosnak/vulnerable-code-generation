//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible fortunes
char *fortunes[] = {
    "You will have a long and happy life.",
    "You will be successful in your career.",
    "You will find true love.",
    "You will travel to many exotic places.",
    "You will make a lot of money.",
    "You will have a happy family.",
    "You will be healthy and strong.",
    "You will be wise and respected.",
    "You will be a good friend.",
    "You will be a great leader."
};

// Get a random fortune
char *get_fortune() {
    // Seed the random number generator
    srand(time(NULL));

    // Get a random index
    int index = rand() % 10;

    // Return the fortune at the random index
    return fortunes[index];
}

// Print the fortune
void print_fortune() {
    // Get a random fortune
    char *fortune = get_fortune();

    // Print the fortune
    printf("%s\n", fortune);
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Automated Fortune Teller!\n");

    // Get the user's name
    char name[256];
    printf("What is your name? ");
    scanf("%s", name);

    // Print a personalized fortune
    printf("Hello, %s! Your fortune is:\n", name);
    print_fortune();

    // Return 0 to indicate success
    return 0;
}