//GEMINI-pro DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random number between 0 and 1
double randDouble() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to generate a random integer between 0 and n-1
int randInt(int n) {
    return (int)floor(randDouble() * n);
}

// Function to generate a random fortune
char *randFortune() {
    // Array of possible fortunes
    char *fortunes[] = {
        "Your future is bright.",
        "You will find success in your endeavors.",
        "A new adventure awaits you.",
        "You will find love and happiness.",
        "You will have a long and prosperous life.",
        "You will overcome all challenges.",
        "You will achieve your goals.",
        "You will find peace and contentment.",
        "You will be successful in all you do.",
        "You will live a happy and fulfilling life."
    };

    // Generate a random index
    int index = randInt(sizeof(fortunes) / sizeof(char *));

    // Return the fortune at the random index
    return fortunes[index];
}

// Function to print a fortune
void printFortune(char *fortune) {
    printf("Your fortune is: %s\n", fortune);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random fortune
    char *fortune = randFortune();

    // Print the fortune
    printFortune(fortune);

    return 0;
}