//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    printf("Move disk %d from ", n);
    if (a == -1)
        printf("A to ");
    else
        printf("A to ");
    if (b == -1)
        printf("B to ");
    else
        printf("B to ");
    if (c == -1)
        printf("C\n");
    else
        printf("C\n");
}

// Recursive function to solve the Tower of Hanoi problem
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function to get user input and call the hanoi function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    char from_rod, to_rod, aux_rod;
    printf("Enter the initial rod: ");
    scanf(" %c", &from_rod);
    printf("Enter the final rod: ");
    scanf(" %c", &to_rod);
    printf("Enter the auxiliary rod: ");
    scanf(" %c", &aux_rod);
    hanoi(n, from_rod, to_rod, aux_rod);
    return 0;
}