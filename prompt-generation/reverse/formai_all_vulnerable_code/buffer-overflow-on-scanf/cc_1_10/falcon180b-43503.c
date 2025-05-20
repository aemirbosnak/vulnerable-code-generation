//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of disks
void print_state(int n, char from_rod, char to_rod, char aux_rod)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%c -> %c\n", from_rod, to_rod);
        else
            printf("%c -> %c\n", from_rod, aux_rod);
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("%c -> %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("%c -> %c\n", from_rod, to_rod);

    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function
int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of disks\n");
        return 0;
    }

    printf("Initial state:\n");
    print_state(n, 'A', 'C', 'B');

    printf("\nFinal state:\n");
    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}