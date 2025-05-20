//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define N 10

// Function to print the tower of Hanoi
void printTower(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("Move disk %d from %c to %c\n", n, from, to);
}

// Function to check if the move is valid
int isValid(int n, int from, int to, int aux) {
    if (from == to || from == aux || to == aux) {
        return 0;
    }
    if (from - to == 1 || from - to == -1) {
        return 1;
    }
    if (from - to == 2 && aux == 1) {
        return 1;
    }
    return 0;
}

// Function to solve the tower of Hanoi
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk %d from %c to %c\n", 1, from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printTower(n, from, to, aux);
    towerOfHanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid number of disks\n");
        return 0;
    }
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}