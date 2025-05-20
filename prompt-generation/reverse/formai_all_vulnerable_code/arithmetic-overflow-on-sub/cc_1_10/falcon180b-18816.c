//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Function to print the current state of the disks
void printState(int n, int from, int to, int aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == from)
            printf("->");
        else if (i == to)
            printf("<-");
        else if (i == aux)
            printf("->");
        else
            printf("   ");
    }
    printf("\n");
}

// Function to move n disks from source to destination
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

// Function to get user input for number of disks
int getInput()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    return n;
}

int main()
{
    int n;
    n = getInput();
    printf("Tower of Hanoi with %d disks\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}