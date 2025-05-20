//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the rod
void printDisks(char rod[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c ", rod[i]);
    }
    printf("\n");
}

// Recursive function to solve the Tower of Hanoi problem
void towerOfHanoi(char fromRod[], char toRod[], char auxRod[], int n) {
    // Base case: if only one disk is left, move it to the destination rod
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod[0], toRod[0]);
        return;
    }

    // Recursive case: move n-1 disks from the source rod to the auxiliary rod
    towerOfHanoi(fromRod, auxRod, toRod, n-1);

    // Move the nth disk from the source rod to the destination rod
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod[0], toRod[0]);

    // Move the n-1 disks from the auxiliary rod to the destination rod
    towerOfHanoi(auxRod, toRod, fromRod, n-1);
}

// Main function to run the program
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the rods with the disks
    char fromRod[MAX] = {0};
    char toRod[MAX] = {0};
    char auxRod[MAX] = {0};
    for(int i=n; i>=1; i--) {
        fromRod[n-i] = 'A' + i;
    }

    // Call the recursive function to solve the Tower of Hanoi problem
    towerOfHanoi(fromRod, toRod, auxRod, n);

    return 0;
}