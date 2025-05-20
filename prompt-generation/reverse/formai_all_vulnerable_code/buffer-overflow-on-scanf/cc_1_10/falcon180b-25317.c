//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function to print the tower of Hanoi
void print_tower(int n, char from_rod, char to_rod, char aux_rod)
{
    int i;
    for (i = n; i >= 1; i--) {
        printf(" ");
    }
    printf("|%c ", from_rod);
    for (i = 1; i <= n; i++) {
        printf(" ");
    }
    printf("|%c\n", to_rod);
}

// Function to move disk from one rod to another
void move_disk(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    move_disk(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    move_disk(n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Main function to run the program
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi for %d disks\n", n);
    printf("From rod: A\nTo rod: C\nAuxiliary rod: B\n");
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}