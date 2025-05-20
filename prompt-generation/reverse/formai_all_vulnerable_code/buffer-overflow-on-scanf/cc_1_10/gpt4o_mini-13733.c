//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to display the instructions to the user
void displayInstructions() {
    printf("Welcome to the Tower of Hanoi Game!\n");
    printf("Your goal is to move a stack of discs from one peg to another,\n");
    printf("following these rules:\n");
    printf("1. Only one disc can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disc from one of the pegs and placing it on top of another peg.\n");
    printf("3. No larger disc may be placed on top of a smaller disc.\n");
    printf("Let's begin! You can choose the number of discs.\n");
}

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        printf("Move disc 1 from peg %c to peg %c\n", from_peg, to_peg);
        return;
    }
    towerOfHanoi(n - 1, from_peg, aux_peg, to_peg);
    printf("Move disc %d from peg %c to peg %c\n", n, from_peg, to_peg);
    towerOfHanoi(n - 1, aux_peg, to_peg, from_peg);
}

// Function to get the number of discs from the user
int getNumberOfDiscs() {
    int n;
    printf("Enter the number of discs (greater than 0): ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("Please enter a valid number of discs: ");
        scanf("%d", &n);
    }
    return n;
}

// Function to play the Tower of Hanoi game
void playTowerOfHanoi() {
    displayInstructions();
    int n = getNumberOfDiscs();
    printf("Solving Tower of Hanoi for %d discs:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
}

// Entry point of the program
int main() {
    playTowerOfHanoi();
    printf("Congratulations! You have successfully solved the Tower of Hanoi puzzle!\n");
    printf("Thank you for playing! Would you like to play again? (yes=1/no=0): ");
    
    int replay;
    scanf("%d", &replay);
    
    while (replay == 1) {
        playTowerOfHanoi();
        printf("Would you like to play again? (yes=1/no=0): ");
        scanf("%d", &replay);
    }
    
    printf("Goodbye! Hope to see you again!\n");
    return 0;
}