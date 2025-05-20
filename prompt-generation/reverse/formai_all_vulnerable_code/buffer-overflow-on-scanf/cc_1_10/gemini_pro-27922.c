//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Oh boy, here we go! Let's dive into the world of recursion!

// "A Towering Tale: The Towers of Hanoi"
// Get ready for a grand adventure, solving the fabled Towers of Hanoi puzzle!

// Declare our three towering pillars.
int towerA[100], towerB[100], towerC[100];

// How tall are our towers? Let's set the initial height.
int towerHeight;

// "Hanoi, Hanoi! Let's Conquer the Heights!"
// Behold, the recursive maestro that will conquer this puzzle.
void solveTowersOfHanoi(int disks, int from, int to, int via) {
    // Witness the magic unfold as we gracefully move disks.
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    // Divide and conquer! Let's break down the problem.
    solveTowersOfHanoi(disks - 1, from, via, to);
    printf("Move disk %d from %c to %c\n", disks, from, to);
    solveTowersOfHanoi(disks - 1, via, to, from);
}

// "Let's Set the Stage: Preparing for the Puzzle"
// Initialize our towers and set the initial configuration.
void initializeTowers() {
    // How tall will our towers stand?
    printf("Behold, the grandeur! Enter the height of our towers (1-100): ");
    scanf("%d", &towerHeight);
    
    // Let's populate Tower A with disks.
    for (int i = 1; i <= towerHeight; i++) {
        towerA[i] = i;
    }
    
    // Let's clear Towers B and C for now.
    for (int i = 1; i <= towerHeight; i++) {
        towerB[i] = 0;
        towerC[i] = 0;
    }
}

// "The Grand Finale: Witness the Towers Dance"
// Let's showcase the triumph of recursion!
int main() {
    initializeTowers();
    
    printf("\nBehold, the enchanted journey begins!\n");
    solveTowersOfHanoi(towerHeight, 'A', 'C', 'B');
    
    printf("\nCongratulations, adventurer! You have conquered the Towers of Hanoi!\n");
    
    return 0;
}