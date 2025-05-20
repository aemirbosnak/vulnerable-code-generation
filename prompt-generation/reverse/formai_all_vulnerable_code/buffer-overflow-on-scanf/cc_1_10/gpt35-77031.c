//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
/*
This program solves the Tower of Hanoi problem using a recursive approach
It takes three inputs:
1. The number of disks
2. The name of the starting pole
3. The name of the target pole

The poles are represented by the characters A, B, and C
*/

#include <stdio.h>

// Function to move the disks
void move_disk(int n, char start_pole, char end_pole) {
    printf("Move disk %d from pole %c to pole %c\n", n, start_pole, end_pole);
}

// Recursive function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int num_disks, char start_pole, char end_pole, char aux_pole) {
    // Base case: only one disk
    if (num_disks == 1) {
        move_disk(num_disks, start_pole, end_pole);
        return;
    }

    // Move (n-1) disks from start pole to auxiliary pole
    solve_tower_of_hanoi(num_disks-1, start_pole, aux_pole, end_pole);

    // Move the remaining disk from start pole to end pole
    move_disk(num_disks, start_pole, end_pole);

    // Move (n-1) disks from auxiliary pole to end pole
    solve_tower_of_hanoi(num_disks-1, aux_pole, end_pole, start_pole);
}

int main() {
    int num_disks;
    char start_pole, end_pole;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("Enter the name of the starting pole (A, B, or C): ");
    scanf(" %c", &start_pole);

    printf("Enter the name of the target pole (A, B, or C): ");
    scanf(" %c", &end_pole);

    // Call the recursive function
    solve_tower_of_hanoi(num_disks, start_pole, end_pole, 'B');

    return 0;
}