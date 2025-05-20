//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("\t");
    }
    printf("%c -> %c\n", from, to);
    if (aux!= '\0') {
        printf("%c -> %c\n", aux, 'A' + n - 1);
    }
}

// Function to check if the move is valid or not
int isValid(int n, int from, int to)
{
    if (from < 0 || from >= n || to < 0 || to >= n) {
        return 0;
    }
    if (to <= from) {
        return 0;
    }
    return 1;
}

// Function to move the disk from one tower to another
void moveDisk(int n, char from, char to, char aux)
{
    printTower(n, from, to, aux);
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        moveDisk(n, from, to, aux);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    moveDisk(n, from, to, aux);
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function to call the towerOfHanoi function
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}