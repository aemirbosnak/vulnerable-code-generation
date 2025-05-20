//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the rod
void printDisks(int rod, int n) {
    int i;
    for (i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("|");
    for (i = 1; i <= n; i++) {
        printf("-");
    }
    printf("|");
    printf("\n");
}

// Function to move the disk from source to destination
void moveDisk(int n, char source, char destination, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    moveDisk(n - 1, source, aux, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisk(n - 1, aux, destination, source);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char source, char destination, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    hanoi(n - 1, source, aux, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    hanoi(n - 1, aux, destination, source);
}

// Main function
int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial configuration:\n");
    printDisks(1, n);

    hanoi(n, 'A', 'C', 'B');

    printf("\nFinal configuration:\n");
    printDisks(1, n);

    return 0;
}