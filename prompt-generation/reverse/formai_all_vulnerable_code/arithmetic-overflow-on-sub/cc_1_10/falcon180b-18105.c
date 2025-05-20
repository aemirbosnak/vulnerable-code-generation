//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define MAX_MOVES 10000

int main() {
    int num_disks;
    int moves = 0;
    int start_rod, end_rod, aux_rod;
    int *stack;
    int top;
    int i;
    clock_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Allocate memory for the stack
    stack = (int *) malloc(num_disks * sizeof(int));
    if (stack == NULL) {
        printf("Error: Out of memory!\n");
        exit(1);
    }

    // Initialize the stack
    top = -1;
    for (i = num_disks - 1; i >= 0; i--) {
        stack[++top] = i;
    }

    // Initialize the starting and ending rods
    start_rod = 1;
    end_rod = 3;

    // Initialize the auxiliary rod
    aux_rod = 2;

    // Start the timer
    start_time = clock();

    // Move the disks from the starting rod to the ending rod
    while (top >= 0) {
        if (stack[top] == num_disks - 1) {
            printf("Move disk %d from rod %d to rod %d\n", num_disks - 1, start_rod, end_rod);
            start_rod = end_rod;
            end_rod = aux_rod;
            aux_rod = 3 - start_rod - end_rod;
        }
        else {
            printf("Move disk %d from rod %d to rod %d\n", stack[top], start_rod, end_rod);
            top--;
            start_rod = end_rod;
            end_rod = aux_rod;
            aux_rod = 3 - start_rod - end_rod;
        }
        moves++;
    }

    // Stop the timer
    end_time = clock();
    elapsed_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Print the total number of moves and elapsed time
    printf("Total number of moves: %d\n", moves);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    // Free the memory used by the stack
    free(stack);

    return 0;
}