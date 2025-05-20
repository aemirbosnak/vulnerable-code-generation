//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if move is valid
int isValidMove(int n, char from, char to, char aux)
{
    // Base case
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return 1;
    }

    // Check if tower of Hanoi is valid
    if (from!= 'A' && from!= 'B' && from!= 'C')
        return 0;
    if (to!= 'A' && to!= 'B' && to!= 'C')
        return 0;
    if (aux!= 'A' && aux!= 'B' && aux!= 'C')
        return 0;

    // Check if move is valid
    if (aux == to || aux == from)
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
    printTower(n, from, to, aux);
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}