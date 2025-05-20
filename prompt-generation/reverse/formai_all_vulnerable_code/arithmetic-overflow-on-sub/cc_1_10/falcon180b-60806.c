//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the stack
void print_stack(int stack[], int n)
{
    int i;
    for (i = 0; i <= n; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to move the disk from source to destination
void move_disk(int stack[], int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from_rod, to_rod);
        return;
    }

    move_disk(stack, n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %d to rod %d\n", n, from_rod, to_rod);

    move_disk(stack, n - 1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    int stack[MAX];
    int i;

    // Initialize the stack
    for (i = n; i >= 1; i--) {
        stack[i] = i;
    }

    // Move the disks from the source rod to the destination rod
    move_disk(stack, n, from_rod, to_rod, aux_rod);
}

int main()
{
    int n, from_rod, to_rod, aux_rod;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Get the rods from the user
    printf("Enter the rods (from, to, auxiliary): ");
    scanf("%d %d %d", &from_rod, &to_rod, &aux_rod);

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}