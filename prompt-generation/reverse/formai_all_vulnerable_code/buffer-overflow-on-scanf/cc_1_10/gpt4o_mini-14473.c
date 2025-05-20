//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Function to perform the Tower of Hanoi algorithm
void solveTowerOfHanoi(int n, char source, char target, char auxiliary, int* moveCount) {
    if (n == 1) {
        (*moveCount)++;
        printf("Move disc 1 from %c to %c\n", source, target);
        return;
    }
    solveTowerOfHanoi(n - 1, source, auxiliary, target, moveCount);
    (*moveCount)++;
    printf("Move disc %d from %c to %c\n", n, source, target);
    solveTowerOfHanoi(n - 1, auxiliary, target, source, moveCount);
}

// Function to return an ordinal suffix for numbers (like 1st, 2nd, etc.)
const char* ordinalSuffix(int number) {
    if (number % 10 == 1 && number % 100 != 11) {
        return "st";
    } else if (number % 10 == 2 && number % 100 != 12) {
        return "nd";
    } else if (number % 10 == 3 && number % 100 != 13) {
        return "rd";
    }
    return "th";
}

// Function to display a header for the program
void displayHeader() {
    printf("=========================================\n");
    printf("|        The Enchanted Tower of Hanoi     |\n");
    printf("=========================================\n");
    printf("Enter the number of discs to be moved:\n");
}

// Main function
int main() {
    int discs;
    int moveCount = 0;

    displayHeader();

    // Accepting input for the number of discs
    printf("Number of discs: ");
    if (scanf("%d", &discs) != 1 || discs < 1) {
        printf("Please enter a valid positive integer for the number of discs.\n");
        return EXIT_FAILURE;
    }

    printf("You have chosen %d disc%s to move!\n", discs, (discs > 1) ? "s" : "");

    // Initiating the solving process
    printf("The magic begins...\n");
    solveTowerOfHanoi(discs, 'A', 'C', 'B', &moveCount);

    // Displaying the number of moves
    printf("Total moves made: %d\n", moveCount);
    printf("Thank you for participating in this enchanted challenge!\n");

    return EXIT_SUCCESS;
}