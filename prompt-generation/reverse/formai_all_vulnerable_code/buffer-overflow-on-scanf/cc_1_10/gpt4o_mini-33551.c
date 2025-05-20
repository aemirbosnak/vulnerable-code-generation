//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Move disk %d from peg %c to peg %c\n", disk, fromPeg, toPeg);
}

void hanoi(int numberOfDisks, char fromPeg, char toPeg, char auxPeg) {
    if (numberOfDisks == 1) {
        moveDisk(1, fromPeg, toPeg);
        return;
    }
    hanoi(numberOfDisks - 1, fromPeg, auxPeg, toPeg);
    moveDisk(numberOfDisks, fromPeg, toPeg);
    hanoi(numberOfDisks - 1, auxPeg, toPeg, fromPeg);
}

void shapeShiftHanoi(int numberOfDisks) {
    char pegs[3] = {'A', 'B', 'C'};
    int rotations = 0;

    printf("Starting the Shape Shifting Tower of Hanoi with %d disks...\n", numberOfDisks);
    while (numberOfDisks > 0) {
        hanoi(numberOfDisks, pegs[0], pegs[2], pegs[1]);
        
        // Rotate pegs
        char temp = pegs[0];
        pegs[0] = pegs[1];
        pegs[1] = pegs[2];
        pegs[2] = temp;

        rotations++;
        printf("Pegs shifted %d time(s): Current pegs %c %c %c\n", rotations, pegs[0], pegs[1], pegs[2]);
        numberOfDisks--;
    }
}

int main() {
    int numberOfDisks;

    printf("Enter the number of disks for the Tower of Hanoi: ");
    scanf("%d", &numberOfDisks);
    
    if (numberOfDisks <= 0) {
        printf("Please enter a positive number of disks.\n");
        return 1; // Exit with error state
    }

    shapeShiftHanoi(numberOfDisks);

    return 0; // Successful execution
}