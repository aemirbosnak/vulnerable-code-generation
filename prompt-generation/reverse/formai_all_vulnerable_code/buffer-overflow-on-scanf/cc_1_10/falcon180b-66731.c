//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the disks on the tower
void print_tower(int tower[], int n) {
    printf("Tower of Hanoi with %d disks:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// Function to move a disk from one peg to another
void move_disk(int tower[], int from, int to, int n) {
    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
        tower[to] = 1;
        tower[from] = 0;
    } else {
        move_disk(tower, from, to - 1, n - 1);
        printf("Move disk %d from peg %d to peg %d\n", n, from, to);
        tower[to] = n;
        tower[from] = 0;
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n) {
    int tower[MAX_DISKS];
    for (int i = 0; i < n; i++) {
        tower[i] = 0;
    }
    tower[0] = 1;
    printf("Initial tower:\n");
    print_tower(tower, n);

    int from = 0;
    int to = 2;
    int aux = 1;
    move_disk(tower, from, to, n);

    from = 1;
    to = 3;
    aux = 2;
    move_disk(tower, from, to, n);

    from = 0;
    to = 3;
    aux = 1;
    move_disk(tower, from, to, n);

    printf("Final tower:\n");
    print_tower(tower, n);
}

// Function to get user input for number of disks
int get_user_input() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid input. Please enter a number between 1 and %d.\n", MAX_DISKS);
        exit(1);
    }
    return n;
}

int main() {
    srand(time(NULL));
    int n = get_user_input();
    tower_of_hanoi(n);
    return 0;
}