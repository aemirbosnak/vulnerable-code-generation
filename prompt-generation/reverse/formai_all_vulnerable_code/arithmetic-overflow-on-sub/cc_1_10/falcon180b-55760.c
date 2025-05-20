//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the elements of an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to move disk from source to destination using third rod
void moveDisk(int n, char source, char destination, char third) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    moveDisk(n - 1, source, third, destination);

    printf("Move disk %d from %c to %c\n", n, source, destination);

    moveDisk(n - 1, third, destination, source);
}

// Function to check if move is valid or not
int isValidMove(int n, int fromRod, int toRod, int thirdRod) {
    if (fromRod == toRod)
        return 0;

    if (thirdRod >= 0 && (fromRod == thirdRod || toRod == thirdRod))
        return 0;

    return 1;
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int n, int fromRod, int toRod, int thirdRod) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", fromRod, toRod);
        return;
    }

    towerOfHanoi(n - 1, fromRod, thirdRod, toRod);

    if (isValidMove(n, fromRod, toRod, thirdRod)) {
        printf("Move disk %d from %d to %d\n", n, fromRod, toRod);
    } else {
        printf("Move disk %d from %d to %d using %d\n", n, fromRod, toRod, thirdRod);
    }

    towerOfHanoi(n - 1, thirdRod, toRod, fromRod);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}