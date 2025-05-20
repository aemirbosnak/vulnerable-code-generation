//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>

// Function to print the solution
void printSolution(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    printSolution(n - 1, source, aux, dest);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    printSolution(n - 1, aux, dest, source);
}

// Function to check if the move is valid
int isValidMove(int n, int from, int to, int aux) {
    if (from == to || from == aux || to == aux)
        return 0;

    if ((from + to - aux) % 2!= 0)
        return 0;

    return 1;
}

// Function to solve the Tower of Hanoi problem
void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }

    if (isValidMove(n, source, dest, aux)) {
        towerOfHanoi(n - 1, source, aux, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        towerOfHanoi(n - 1, aux, dest, source);
    }
}

// Driver code
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");

    printSolution(n, 'A', 'C', 'B');

    return 0;
}