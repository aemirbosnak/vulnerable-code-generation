//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the disks on a peg
void print_disks(int peg, int n) {
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", peg + i);
    }
    printf("\n");
}

// Function to move n disks from source peg to target peg using auxiliary peg
void hanoi(int n, int source, int target, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", source, target);
        return;
    }

    hanoi(n - 1, source, aux, target);

    printf("Move disk %d from %d to %d\n", n, source, target);

    hanoi(n - 1, aux, target, source);
}

// Function to get user input for number of disks
int get_num_disks() {
    int num_disks;

    printf("Enter the number of disks (1 to %d): ", MAX_DISKS);
    scanf("%d", &num_disks);

    while (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid input. Enter the number of disks (1 to %d): ", MAX_DISKS);
        scanf("%d", &num_disks);
    }

    return num_disks;
}

int main() {
    int num_disks = get_num_disks();

    printf("Tower of Hanoi with %d disks:\n", num_disks);

    // Initialize pegs with disks
    int source = 0;
    int target = num_disks - 1;
    int aux = num_disks - 1;

    for (int i = num_disks - 1; i >= 0; i--) {
        printf("Move disk %d from %d to %d\n", i + 1, source, target);
        source--;
        target--;
    }

    // Print initial state of pegs
    printf("Initial state:\n");
    print_disks(source, num_disks);
    print_disks(target, num_disks);

    // Solve the Tower of Hanoi problem
    hanoi(num_disks, source, target, aux);

    // Print final state of pegs
    printf("Final state:\n");
    print_disks(source, num_disks);
    print_disks(target, num_disks);

    return 0;
}