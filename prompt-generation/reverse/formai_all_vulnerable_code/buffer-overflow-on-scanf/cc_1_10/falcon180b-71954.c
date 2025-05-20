//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to move a disk from one peg to another
void moveDisk(int n, char from, char to) {
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }
    moveDisk(n-1, from, 'A');
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    moveDisk(n-1, 'A', to);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    // Base case
    if(n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
        return;
    }
    // Recursive case
    hanoi(n-1, from, aux, to);
    printf("Move disk %d from peg %c to peg %c\n", n, from, to);
    hanoi(n-1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if(n > MAX) {
        printf("Error: Number of disks cannot be greater than %d\n", MAX);
        return -1;
    }
    printf("Solving the Tower of Hanoi problem for %d disks...\n", n);
    // Solve the problem
    hanoi(n, 'A', 'C', 'B');
    return 0;
}