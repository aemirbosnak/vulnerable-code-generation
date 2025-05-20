//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from %c to %c\n", from, to);
        else if (i == n - 1)
            printf("Move disk %d from %c to %c\n", n, from, to);
        else
            printf("Move disk %d from %c to %c\n", n - i, from, aux);
    }
}

// Function to check if move is valid or not
int isValid(int n, char from, char to, char aux)
{
    // Base case
    if (n == 0)
        return 1;

    // Check if the move is valid or not
    if ((from == 'A' && to == 'C' && aux!= 'B') ||
        (from == 'A' && to == 'B' && aux!= 'C') ||
        (from == 'B' && to == 'A' && aux!= 'C') ||
        (from == 'B' && to == 'C' && aux!= 'A') ||
        (from == 'C' && to == 'A' && aux!= 'B') ||
        (from == 'C' && to == 'B' && aux!= 'A'))
        return 1;

    return 0;
}

// Function to solve the tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);

    printf("Move disk %d from %c to %c\n", n, from, to);

    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }

    printf("Solving the Tower of Hanoi problem with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}