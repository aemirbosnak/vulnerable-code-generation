//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the pattern of tower
void printTower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", from);
        from++;
        if (i == n - 1) {
            printf("%c\n", to);
        }
    }
}

// Function to check if move is valid or not
int isValid(int n, char from, char to, char aux)
{
    if (from > to || from < 0 || to < 0) {
        return 0;
    }
    return 1;
}

// Function to move the disk from one rod to another
void move(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("%c -> %c\n", from, to);
        return;
    }

    move(n - 1, from, aux, to);
    printf("%c -> %c\n", from, to);
    move(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("%c -> %c\n", from, to);
        return;
    }

    towerOfHanoi(n - 1, from, aux, to);
    printf("%c -> %c\n", from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Driver program to test above functions
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }

    printf("Tower of Hanoi with %d disks:\n", n);
    printTower(n, 'A', 'C', 'B');
    printf("\n");

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}