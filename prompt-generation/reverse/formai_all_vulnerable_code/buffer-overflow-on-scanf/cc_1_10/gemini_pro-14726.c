//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// 3 pillars
int pillars[3];

// n disks in total
int n;

// keeps track of the last disk moved
int last_moved = -1;

// moves a disk from one pillar to another
void move(int from, int to) {
    if (pillars[from] == pillars[to]) {
        return;
    }

    // move the smallest disk
    if (pillars[from] < pillars[to]) {
        pillars[to] = pillars[from];
        pillars[from] = 0;
    } else {
        pillars[from] = pillars[to];
        pillars[to] = 0;
    }

    last_moved = to;
}

// solves the Tower of Hanoi problem
void solve(int n, int from, int to, int via) {
    if (n <= 1) {
        move(from, to);
        return;
    }

    solve(n - 1, from, via, to);
    move(from, to);
    solve(n - 1, via, to, from);
}

// prints the current state of the pillars
void print_pillars() {
    for (int i = 0; i < 3; i++) {
        printf("%d ", pillars[i]);
    }
    printf("\n");
}

int main() {
    // get the number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // initialize the pillars
    for (int i = 0; i < 3; i++) {
        pillars[i] = 0;
    }

    // place all disks on the first pillar
    for (int i = n; i > 0; i--) {
        pillars[0] = i;
    }

    // solve the puzzle
    solve(n, 0, 2, 1);

    // print the final state of the pillars
    print_pillars();

    return 0;
}