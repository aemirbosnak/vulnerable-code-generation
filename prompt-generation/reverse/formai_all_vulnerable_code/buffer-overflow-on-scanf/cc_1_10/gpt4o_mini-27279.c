//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function

#define MAX_DISKS 10

void moveDisk(int fromPeg, int toPeg);
void displayPegs(int pegs[], int numDisks);
void hanoi(int n, int fromPeg, int toPeg, int auxPeg);
void delay(int seconds);

int main() {
    int numDisks;

    printf("Welcome to the Tower of Hanoi Game! 🌟\n");
    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &numDisks);

    if (numDisks < 1 || numDisks > MAX_DISKS) {
        printf("Invalid number of disks! Please run the program again.\n");
        return 1;
    }

    int pegs[3] = {0};

    printf("\nInitial State:\n");
    displayPegs(pegs, numDisks);

    hanoi(numDisks, 1, 3, 2);

    printf("\nAll disks moved to peg 3! 🎉\n");
    return 0;
}

void hanoi(int n, int fromPeg, int toPeg, int auxPeg) {
    if (n == 1) {
        moveDisk(fromPeg, toPeg);
        return;
    }
    hanoi(n - 1, fromPeg, auxPeg, toPeg);
    moveDisk(fromPeg, toPeg);
    hanoi(n - 1, auxPeg, toPeg, fromPeg);
}

void moveDisk(int fromPeg, int toPeg) {
    printf("Moving disk from peg %d to peg %d\n", fromPeg, toPeg);
    delay(1);
}

void displayPegs(int pegs[], int numDisks) {
    for (int i = numDisks - 1; i >= 0; i--) {
        for (int peg = 1; peg <= 3; peg++) {
            if (pegs[peg - 1] == i + 1) {
                for (int j = 0; j < (i + 1) * 2 - 1; j++) {
                    printf("=");
                }
                printf("  ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    printf("  1      2      3\n");
    fflush(stdout);
}

void delay(int seconds) {
    sleep(seconds);
}