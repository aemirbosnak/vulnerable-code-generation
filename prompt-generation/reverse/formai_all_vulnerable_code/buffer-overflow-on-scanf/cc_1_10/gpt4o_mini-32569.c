//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: immersive
#include <stdio.h>

void moveDisk(int disk, char fromRod, char toRod) {
    printf("\nMoving disk %d from %c to %c", disk, fromRod, toRod);
}

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(n, fromRod, toRod);
        return;
    }
    
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    moveDisk(n, fromRod, toRod);
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

void welcomeMessage() {
    printf("=========================================\n");
    printf("           Welcome to Tower of Hanoi\n");
    printf("         A magical world of puzzles\n");
    printf("=========================================\n\n");
    printf("Your objective is to move all the disks from one rod to another,\n");
    printf("following these rules:\n");
    printf("1. Only one disk can be moved at a time.\n");
    printf("2. Each move consists of taking the upper disk from one stack and\n");
    printf("   placing it on top of another stack or on an empty rod.\n");
    printf("3. No larger disk may be placed on top of a smaller disk.\n\n");
}

int main() {
    int n;
    welcomeMessage();

    printf("Enter the number of disks (1 to 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number of disks! Please choose between 1 and 10.\n");
        return 1;
    }

    printf("\nLet's embark on the journey of moving %d disks.\n", n);
    printf("The rods are represented as A (from), B (to), C (auxiliary).\n");
    
    towerOfHanoi(n, 'A', 'B', 'C');

    printf("\n\nCongratulations! You have successfully moved %d disks from rod A to rod B!\n", n);
    printf("Now you have mastered the puzzle of the Tower of Hanoi!\n");
    printf("=========================================\n");

    return 0;
}