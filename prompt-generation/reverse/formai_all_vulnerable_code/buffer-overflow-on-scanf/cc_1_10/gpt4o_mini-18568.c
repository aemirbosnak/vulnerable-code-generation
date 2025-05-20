//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void moveDisk(int disk, char fromPeg, char toPeg) {
    printf("Woohoo! Moving disk %d from peg %c to peg %c!\n", disk, fromPeg, toPeg);
}

void solveHanoi(int n, char fromPeg, char toPeg, char auxPeg) {
    // Base case: If there's only one disk to move
    if (n == 1) {
        moveDisk(n, fromPeg, toPeg);
        return;
    }
    // Recursive case: Move n-1 disks from the source peg to the auxiliary peg
    solveHanoi(n - 1, fromPeg, auxPeg, toPeg);
    
    // Move the nth disk from source to target peg
    moveDisk(n, fromPeg, toPeg);
    
    // Move the n-1 disks from auxiliary peg to target peg
    solveHanoi(n - 1, auxPeg, toPeg, fromPeg);
}

int main() {
    int disks;

    // Welcome to the Tower of Hanoi - Where disks dare to be moved!
    printf("Welcome to the Tower of Hanoi Misadventure!\n");
    printf("How many disks do you dare to juggle? ('0' to escape this madness): ");
    scanf("%d", &disks);

    // Let's not scare anyone with 0 or less disks
    if (disks <= 0) {
        printf("Oops, it seems like you have no disks! Go play with something else!\n");
        return 0;
    }

    // Put on your safety goggles, we're about to get crazy!
    printf("You've chosen to juggle %d disks! Let's roll!\n", disks);

    // Let's solve the puzzle!
    printf("Here comes the epic saga of moving disks!\n");
    solveHanoi(disks, 'A', 'C', 'B');
    
    // Trick or Disk: The grand finale!
    printf("All disks have been successfully moved!\n");
    printf("As a reward, you get to keep all the disks! (Not that we were going to take them back anyway!)\n");
    printf("Remember: No disks were harmed during this performance, they were just... temporarily relocated!\n");

    // Time for some Tower of Hanoi trivia!
    printf("Did you know? If you take too long to solve the Hanoi, the disks might start talking!\n");
    printf("They might complain about their weight and size - disk #3 has been whining about it for ages!\n");
    
    // Signing off from the Tower of Hanoi!
    printf("Thank you for joining the Tower of Hanoi Misadventure! Until next time, keep those disks spinning!\n");

    return 0;
}