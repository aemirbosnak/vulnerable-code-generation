//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void printTower(int n, int from, int to, int aux, char *msg) {
    int i;
    printf("\n%s\n", msg);
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("Move disk %d from rod %c to rod %c\n", n, 'A' + from, 'A' + to);
    printf("\n");
}

// Function to check if a move is valid
int isValid(int n, int from, int to, int aux) {
    if (from == to)
        return 1;
    if (from == aux || to == aux)
        return 0;
    return 1;
}

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to move n disks from fromRod to toRod with the help of auxRod
void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printTower(n, fromRod, toRod, auxRod, "Move top disk");
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

// Driver program to test above functions
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}