//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("Move disk 1 from rod %c to rod %c\n", from, to);
        else if (i == n - 1)
            printf("Move disk %d from rod %c to rod %c\n", n, from, to);
        else
            printf("Move disk %d from rod %c to rod %c\n", n - i, from, to);
    }
}

// Function to check if a move is valid
int isValid(int n, int from, int to, int aux)
{
    if (from >= 0 && to >= 0 && aux >= 0 && from!= to && aux!= from && aux!= to)
        return 1;
    else
        return 0;
}

// Function to check if the game is over
int isOver(int n, int from, int to, int aux)
{
    if (n == 0)
        return 1;
    else if (isValid(n - 1, from, to, aux))
        return 0;
    else
        return 1;
}

// Function to solve the tower of Hanoi problem
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printTower(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

// Main function
int main()
{
    int n, i;
    char from, to, aux;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Solving the Tower of Hanoi problem for %d disks\n", n);

    for (i = n; i >= 1; i--) {
        printf("Solving for %d disks...\n", i);
        hanoi(i, 'A', 'C', 'B');
    }

    return 0;
}