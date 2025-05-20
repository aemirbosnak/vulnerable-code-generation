//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>

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
            printf("Move disk %d from rod %c to rod %c\n", i + 1, from, to);
    }
}

// Function to check if it is possible to move n disks from from_rod to to_rod
int isPossible(int n, char from_rod, char to_rod)
{
    if (n == 0)
        return 1;
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return 1;
    }
    int count = 0;
    int k = 1;
    while (k <= n) {
        if (count == 0) {
            printf("Move disk %d from rod %c to rod %c\n", k, from_rod, to_rod);
            count++;
        }
        if (k == n) {
            printf("Move disk %d from rod %c to rod %c\n", k, from_rod, to_rod);
            count--;
        }
        k++;
    }
    if (count == 0)
        return 1;
    else
        return 0;
}

// Function to solve the tower of Hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\n");
    return 0;
}