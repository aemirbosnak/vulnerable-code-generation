//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function to print the tower of hanoi
void print_tower(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == from) {
            printf(" %d ", i);
        } else {
            printf(" %d ", 0);
        }
    }
    printf("\n");
}

// Function to move a disk from one peg to another
void move_disk(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    move_disk(n - 1, from, aux, to);
    printf("Move disk %d from %d to %d\n", n, from, to);
    move_disk(n - 1, aux, to, from);
}

// Function to solve the tower of hanoi problem
void tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from %d to %d\n", from, to);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %d to %d\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

// Main function
int main() {
    int n, from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the starting peg: ");
    scanf("%d", &from);
    printf("Enter the ending peg: ");
    scanf("%d", &to);
    printf("Enter the auxiliary peg: ");
    scanf("%d", &aux);
    printf("\nTower of Hanoi problem with %d disks:\n", n);
    print_tower(n, from, to, aux);
    printf("\n");
    tower_of_hanoi(n, from, to, aux);
    printf("\n");
    return 0;
}