//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

#define MAX_DISKS 8

// Structure to represent a disk
typedef struct {
    int num;
    int pos[2]; // x, y coordinates
} Disk;

// Function to move a disk from one peg to another
void moveDisk(Disk* disk, int fromPeg, int toPeg, int nPegs) {
    int i;
    Disk temp;

    // Move the disk from its current peg to the intermediate peg
    for (i = 0; i < nPegs; i++) {
        temp = disk[fromPeg];
        disk[fromPeg] = disk[toPeg];
        disk[toPeg] = temp;
        fromPeg = (fromPeg + 1) % nPegs;
        toPeg = (toPeg + 1) % nPegs;
    }
}

// Function to solve the Tower of Hanoi problem
void solveTowerOfHanoi(Disk* disks, int nPegs) {
    int i, j;

    // Base case: if there is only one disk, move it to the destination peg
    if (nPegs == 1) {
        moveDisk(disks, 0, nPegs - 1, nPegs);
        return;
    }

    // Recursively move the disks from the source peg to the destination peg
    solveTowerOfHanoi(disks, 0);
    moveDisk(disks, 0, nPegs - 1, nPegs);
    solveTowerOfHanoi(disks, nPegs);
}

// Function to print the current state of the Tower of Hanoi
void printTower(Disk* disks, int nPegs) {
    int i, j;

    printf("Disk %d\n", disks[0].num);
    for (i = 1; i < nPegs; i++) {
        printf("Disk %d: ", disks[i].num);
        for (j = 0; j < 2; j++) {
            printf("%d, ", disks[i].pos[j]);
        }
        printf("\n");
    }
    printf("Disk %d\n", disks[nPegs - 1].num);
}

// Function to read disks from the user
void readDisks(Disk* disks, int nDisks) {
    int i, j;
    for (i = 0; i < nDisks; i++) {
        printf("Enter disk %d's position (x, y): ", i + 1);
        scanf("%d, %d", &disks[i].pos[0], &disks[i].pos[1]);
        disks[i].num = i + 1;
    }
}

int main() {
    Disk disks[MAX_DISKS];
    int nDisks, nPegs;

    printf("Enter the number of disks: ");
    scanf("%d", &nDisks);
    printf("Enter the number of pegs: ");
    scanf("%d", &nPegs);

    readDisks(disks, nDisks);
    solveTowerOfHanoi(disks, nPegs);
    printTower(disks, nPegs);

    return 0;
}