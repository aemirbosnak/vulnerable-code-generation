//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%c\n", to);
        else
            printf("%c ", to);
    }

    for (i = n - 1; i >= 0; i--) {
        if (i == 0)
            printf("%c\n", from);
        else
            printf("%c ", from);
    }
}

// Recursive function to solve the tower of Hanoi problem
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

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Tower of Hanoi with %d disks:\n", n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}