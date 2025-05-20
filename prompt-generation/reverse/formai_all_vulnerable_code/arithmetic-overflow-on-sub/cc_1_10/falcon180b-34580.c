//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define N 5

// function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to move a disk from source to destination
void moveDisk(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    moveDisk(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    moveDisk(n - 1, aux, to, from);
}

// function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

// main function
int main() {
    int disk[N];
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Move %d disks from rod A to rod C\n", n);
    hanoi(n, 'A', 'C', 'B');
    printf("Move %d disks from rod A to rod B\n", n);
    hanoi(n, 'A', 'B', 'C');
    printf("Move %d disks from rod B to rod A\n", n);
    hanoi(n, 'B', 'A', 'C');
    return 0;
}