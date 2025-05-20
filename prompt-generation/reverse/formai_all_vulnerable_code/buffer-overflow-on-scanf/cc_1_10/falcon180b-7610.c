//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: happy
#include <stdio.h>

#define MAX 100

// Function to print the Hanoi tower
void printTower(int n, char from, char to, char aux)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("%c ", 'A' + n - 1);
        else if (i % 2 == 0)
            printf("%c ", 'A' + n - 1 - i / 2);
        else
            printf("%c ", 'A' + i / 2 + 1);
    }

    printf("\n");
}

// Function to move the top disk from fromRod to toRod
void moveDisk(int n, char fromRod, char toRod, char auxRod)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    moveDisk(n - 1, fromRod, auxRod, toRod);

    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);

    moveDisk(n - 1, auxRod, toRod, fromRod);
}

// Function to solve the Hanoi tower problem
void hanoi(int n, char fromRod, char toRod, char auxRod)
{
    if (n <= 0)
        return;
    else if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }

    hanoi(n - 1, fromRod, auxRod, toRod);

    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);

    hanoi(n - 1, auxRod, toRod, fromRod);
}

// Main function
int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');

    return 0;
}