//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
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
        else if (i % 2 == 0)
            printf("Move disk %d from %c to %c\n", i + 1, from, to);
        else
            printf("Move disk %d from %c to %c\n", i + 1, from, aux);
    }
}

// Function to check if move is valid
int isValidMove(int n, int from, int to)
{
    if (from < 0 || from >= n || to < 0 || to >= n || from == to)
        return 0;
    return 1;
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
    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");
    printf("Press any key to exit.\n");
    getchar();
    return 0;
}