//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the towers
void printTowers(char tower1[], char tower2[], char tower3[], int top) {
    int i;

    printf("\n");

    for (i = top; i >= 0; i--) {
        if (i < top)
            printf(" ");

        if (tower1[i]!= '\0')
            printf("%c ", tower1[i]);
        else
            printf("  ");
    }

    printf("\n");

    for (i = top; i >= 0; i--) {
        if (i < top)
            printf(" ");

        if (tower2[i]!= '\0')
            printf("%c ", tower2[i]);
        else
            printf("  ");
    }

    printf("\n");

    for (i = top; i >= 0; i--) {
        if (i < top)
            printf(" ");

        if (tower3[i]!= '\0')
            printf("%c ", tower3[i]);
        else
            printf("  ");
    }
}

// Function to check if a move is valid or not
int isValidMove(char from[], char to[], int n) {
    if (from[n] == '\0' || to[n] == '\0')
        return 0;

    return 1;
}

// Function to move a disk from one tower to another
void moveDisk(char from[], char to[], int n) {
    char temp = from[n];
    from[n] = '\0';
    to[n] = temp;
}

// Function to solve the Tower of Hanoi problem recursively
void towerOfHanoi(char from[], char to[], char aux[], int n) {
    if (n == 1) {
        moveDisk(from, to, n);
        printTowers(from, to, aux, n - 1);
        return;
    }

    towerOfHanoi(from, aux, to, n - 1);
    moveDisk(from, to, n);
    printTowers(from, to, aux, n - 1);
}

// Main function
int main() {
    char tower1[MAX], tower2[MAX], tower3[MAX];
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial state:\n");
    for (int i = n; i >= 1; i--) {
        tower1[i-1] = 'A' + i;
    }

    tower2[0] = '\0';
    tower3[0] = '\0';

    printf("\nFinal state:\n");
    towerOfHanoi(tower1, tower3, tower2, n);

    return 0;
}