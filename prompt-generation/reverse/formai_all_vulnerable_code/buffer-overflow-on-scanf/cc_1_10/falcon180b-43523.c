//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("%c -> %c -> %c\n", from, to, aux);
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to) {
    if(from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move the disk from one tower to another
void move_disk(int n, char from, char to, int *towers) {
    int i;
    for(i=n-1; i>=0; i--) {
        if(towers[i] == from) {
            towers[i] = to;
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux) {
    int towers[3][MAX_DISKS];
    int i, j;

    // Initialize the towers
    for(i=0; i<3; i++) {
        for(j=0; j<n; j++) {
            towers[i][j] = 'A' + j;
        }
    }

    // Move n-1 disks from from to to, using aux as auxiliary tower
    for(i=n-1; i>=0; i--) {
        move_disk(n, from, to, towers[0]);
        move_disk(n, from, to, towers[1]);
        move_disk(n, from, to, towers[2]);
    }

    // Print the final state of the towers
    print_towers(n, from, to, aux);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}