//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to move a disk from source to destination
void moveDisk(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveDisk(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisk(n - 1, auxiliary, destination, source);
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of disks!\n");
        return 0;
    }
    printf("Original tower:\n");
    int arr[n];
    for (int i = n; i >= 1; i--) {
        arr[n - i] = i;
        printArray(arr, n);
    }
    printf("Solved tower:\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}