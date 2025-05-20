//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

// Function to print the disks in a tower
void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to move a disk from source to destination
void move_disk(int tower[], int n, int from, int to) {
    if (n == 1) {
        printf("Moving disk 1 from %d to %d\n", from, to);
        tower[to] = tower[from];
        tower[from] = 0;
        return;
    }
    int aux = (from == 0)? to : 0;
    move_disk(tower, n - 1, from, aux);
    printf("Moving disk %d from %d to %d\n", n, from, to);
    tower[to] = tower[from];
    tower[from] = 0;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Moving disk 1 from %d to %d\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Moving disk %d from %d to %d\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n, from, to;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int tower[MAX_DISKS];
    for (int i = n; i > 0; i--) {
        tower[i] = i;
    }
    printf("Initial tower:\n");
    print_tower(tower, n);
    printf("Enter the starting rod: ");
    scanf("%d", &from);
    printf("Enter the ending rod: ");
    scanf("%d", &to);
    printf("Solving the Tower of Hanoi problem...\n");
    hanoi(n, from, to, (from == 0)? to : 0);
    printf("Final tower:\n");
    print_tower(tower, n);
    return 0;
}