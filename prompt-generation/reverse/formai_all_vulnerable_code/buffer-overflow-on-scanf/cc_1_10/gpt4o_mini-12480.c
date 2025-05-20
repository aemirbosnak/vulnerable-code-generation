//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printFibonacci(int n, int a, int b, int currentTerm) {
    // Base case: when we reach the specified terms
    if (currentTerm >= n) {
        return;
    }

    // Calculate the next value in the Fibonacci sequence
    int c = a + b;

    // Randomly decide whether to print a special message or the Fibonacci number
    int randomChoice = rand() % 5; // Random number between 0 and 4
    if (randomChoice == 0) {
        printf("Whoa! This is a twist at term %d! 🎉\n", currentTerm + 1);
    } else {
        printf("Fibonacci Term %d: %d\n", currentTerm + 1, c);
    }

    // Recur with updated values
    printFibonacci(n, b, c, currentTerm + 1);
}

void startInteraction() {
    int n;
    printf("Welcome to the Mind-Bending Fibonacci Sequence Generator! 🌌\n");
    printf("How many terms of Fibonacci do you wish to discover? (Enter a number greater than 0): ");
    scanf("%d", &n);

    // Validate user input
    if (n <= 0) {
        printf("Please enter a valid positive integer!\n");
        startInteraction(); // Recursive prompt for a valid input
        return;
    }

    printf("\nGenerating Fibonacci terms...\n");
    printFibonacci(n, 0, 1, 0);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Start the interaction
    startInteraction();

    // Ask the user if they want to try again
    char choice;
    do {
        printf("\nWould you like to explore the Fibonacci sequence again? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y') {
            startInteraction();
        } else if (choice == 'n' || choice == 'N') {
            printf("Thank you! Keep shining like the stars! ✨\n");
        } else {
            printf("Hmm... I didn't get that. Trying again...\n");
        }
    } while (choice != 'n' && choice != 'N');

    return 0;
}