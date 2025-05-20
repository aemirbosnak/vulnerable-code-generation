//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("%c ", 'A' + n - 1);
        else
            printf("%c ", 'A' + i - 1);
    }
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if the move is valid
bool isValid(int n, char from, char to)
{
    if (from == to)
        return false;
    if (from == 'A' && to == 'C')
        return false;
    if (from == 'B' && to == 'A')
        return false;
    return true;
}

// Function to move the disk from one peg to another
void moveDisk(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    moveDisk(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveDisk(n - 1, aux, to, from);
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
    srand(time(NULL));
    char from = 'A' + rand() % 3;
    char to = 'C';
    char aux = 'B';
    if (from == to) {
        from = 'B';
        to = 'A';
    }
    if (from == 'C' && to == 'A') {
        from = 'A';
        to = 'C';
    }
    printf("Initial state:\n");
    printTower(n, from, to, aux);
    printf("\n");
    printf("Solving the tower of Hanoi problem...\n");
    towerOfHanoi(n, from, to, aux);
    printf("\n");
    printf("Final state:\n");
    printTower(n, from, to, aux);
    return 0;
}