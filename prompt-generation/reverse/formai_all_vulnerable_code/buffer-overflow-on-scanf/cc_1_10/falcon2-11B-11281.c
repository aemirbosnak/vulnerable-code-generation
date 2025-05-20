//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Function to move n discs from one peg to another
int move_discs(int n, int source_peg, int destination_peg, int spare_peg) {
    // Base case: if there is only one disc left
    if (n == 1) {
        printf("Move disc %d from peg %d to peg %d\n", n, source_peg, destination_peg);
        return 0;
    }
    
    // Recursive case: move the top n-1 discs and then move the remaining disc
    int remaining_n_minus_one = n - 1;
    if (remaining_n_minus_one == 0) {
        return move_discs(n - 1, source_peg, spare_peg, destination_peg);
    } else if (remaining_n_minus_one == 1) {
        return move_discs(remaining_n_minus_one, source_peg, destination_peg, spare_peg);
    } else {
        return move_discs(remaining_n_minus_one, source_peg, spare_peg, destination_peg) +
            move_discs(remaining_n_minus_one, destination_peg, source_peg, spare_peg);
    }
}

// Function to get the minimum number of steps to solve the Tower of Hanoi Problem
int get_hanoi_steps(int n, int source_peg, int destination_peg, int spare_peg) {
    int steps = 0;
    while (n > 0) {
        steps += move_discs(n, source_peg, destination_peg, spare_peg);
        n--;
    }
    return steps;
}

// Function to print the steps to solve the Tower of Hanoi Problem
void print_hanoi_steps(int n, int source_peg, int destination_peg, int spare_peg) {
    int steps = get_hanoi_steps(n, source_peg, destination_peg, spare_peg);
    printf("The minimum number of steps to solve the Tower of Hanoi Problem with %d discs is %d.\n", n, steps);
}

// Main function
int main() {
    int n;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    int source_peg = 0;
    int destination_peg = 1;
    int spare_peg = 2;
    print_hanoi_steps(n, source_peg, destination_peg, spare_peg);
    return 0;
}