//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the towers
void print_towers(int n, int from, int to, int aux) {
    int i;
    for (i = 0; i <= n; ++i) {
        if (i!= from && i!= to && i!= aux)
            printf(" %d ", i);
        else
            printf(" %d ", i);
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to, int aux) {
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n)
        return 0;
    if (to == aux || from == to)
        return 0;
    return 1;
}

// Function to move disk from one rod to another
void move_disk(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
        return;
    }
    move_disk(n - 1, from, aux, to);
    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
    move_disk(n - 1, aux, to, from);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %d to rod %d\n", n, from, to);
    tower_of_hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The initial state of the towers:\n");
    print_towers(n, 0, 2, 1);
    printf("\n");
    tower_of_hanoi(n, 0, 2, 1);
    return 0;
}