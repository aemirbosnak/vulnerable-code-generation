//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to print the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("%c -> %c -> %c\n", from, to, aux);
}

// Function to check if a move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int n, char from, char to, int *tower) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (tower[i] == from) {
            tower[i] = to;
            break;
        }
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    int i;
    int *tower = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        tower[i] = 'A' + i;
    }
    printf("Tower of Hanoi problem with %d disks\n", n);
    print_towers(n, from, to, aux);
    if (n == 1) {
        move_disk(n, from, to, tower);
        print_towers(n, from, to, aux);
        free(tower);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, tower);
    print_towers(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
    free(tower);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}