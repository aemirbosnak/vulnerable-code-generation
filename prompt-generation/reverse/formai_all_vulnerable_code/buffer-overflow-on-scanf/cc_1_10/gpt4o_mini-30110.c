//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_peg, to_peg);
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    printf("Move disk %d from %c to %c\n", n, from_peg, to_peg);
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

// Function to get input from the user safely
int getUserInput() {
    int n;
    printf("Enter the number of disks (positive integer): ");
    while (1) {
        if (scanf("%d", &n) != 1 || n <= 0) {
            printf("Invalid input. Please enter a positive integer: ");
            while (getchar() != '\n'); // clear the input buffer
        } else {
            break;
        }
    }
    return n;
}

// A function to display a styled introduction
void displayIntro() {
    printf("**************************************************\n");
    printf("                    Tower of Hanoi                \n");
    printf("**************************************************\n");
    printf("This program solves the Tower of Hanoi puzzle\n");
    printf("using recursion.\n\n");
}

// Main function to execute the program
int main() {
    int n; // Number of disks
    
    displayIntro(); // Display introduction
    
    n = getUserInput();  // Get user input
    
    printf("\nThe sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    
    printf("\nAll disks moved successfully from rod A to rod C.");
    
    return EXIT_SUCCESS;
}

/*
    Author: Donald Knuth
    Date: 20xx-xx-xx
    Description: This C program implements the Tower of Hanoi problem using a 
    recursive approach. It prompts the user for the number of disks and outputs 
    the moves required to solve the puzzle.
*/

// Utility function to pause the execution
void pauseExecution() {
    printf("\nPress Enter to exit...");
    while(getchar() != '\n'); // Wait till user presses Enter
}

// A function to demonstrate complexity
void demonstrateComplexity(int n) {
    printf("\nSolving Tower of Hanoi for %d disks involves %d moves.\n", n, (1 << n) - 1);
    printf("This is due to the recursive nature of the solution, which grows exponentially.\n");
}