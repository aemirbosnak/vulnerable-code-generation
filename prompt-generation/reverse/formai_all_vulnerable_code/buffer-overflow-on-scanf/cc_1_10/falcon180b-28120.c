//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to check if a move is valid or not
int isValid(int n, int from, int to, int aux[], int top) {
    if (from < 0 || to < 0 || from >= n || to >= n || top < 0 || top >= n) {
        return 0;
    }
    if (from == to) {
        return 0;
    }
    if (from == top || to == top) {
        return 0;
    }
    return 1;
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int n, int from, int to, int aux[], int top) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (isValid(n, from, to, aux, top)) {
            hanoi(n - 1, from, aux[top], aux, top - 1);
            hanoi(1, from, to, aux, top);
            hanoi(n - 1, aux[top], to, aux, top - 1);
        }
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int from = 0, to = 2 * n - 1, aux[MAX];
    hanoi(n, from, to, aux, 0);
    return 0;
}