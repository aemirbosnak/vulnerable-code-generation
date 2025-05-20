//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of Hanoi
void printTower(char arr[], int n, int front, int rear, int aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == front)
            printf(" %c ", arr[i]);
        else if (i == rear)
            printf(" %c ", arr[i]);
        else if (i == aux)
            printf(" %c ", arr[i]);
        else
            printf(" %c ", arr[i]);
    }
}

// Recursive function to solve the tower of Hanoi problem
void towerOfHanoi(char arr[], int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(arr, n - 1, from_rod, aux_rod, to_rod);
    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(arr, n - 1, aux_rod, to_rod, from_rod);
}

// Main function to run the program
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char arr[n];
    printf("Enter the disks in order: ");
    for (int i = 0; i < n; i++) {
        scanf("%c", &arr[i]);
    }
    printf("\n\nInitial state:\n");
    printTower(arr, n, 'A', 'C', 'B');
    towerOfHanoi(arr, n, 'A', 'C', 'B');
    printf("\n\nFinal state:\n");
    printTower(arr, n, 'A', 'B', 'C');
    return 0;
}