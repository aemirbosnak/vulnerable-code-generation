//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int towers[3][MAX_DISKS], int n)
{
    int i, j;
    for (i = 0; i <= 2; i++) {
        printf("Tower %d: ", i);
        for (j = n - 1; j >= 0; j--) {
            if (towers[i][j]!= -1) {
                printf("%d ", towers[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int towers[3][MAX_DISKS], int from, int to, int n)
{
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    if (towers[from][n - 1] > towers[to][n - 1]) {
        return 0;
    }
    return 1;
}

// Function to move a disk from one tower to another
void move_disk(int towers[3][MAX_DISKS], int from, int to, int n)
{
    int temp = towers[from][n - 1];
    towers[from][n - 1] = -1;
    towers[to][n - 1] = temp;
}

// Function to solve the Tower of Hanoi problem recursively
void hanoi(int towers[3][MAX_DISKS], int n, int from, int to, int aux)
{
    if (n == 1) {
        move_disk(towers, from, to, n);
        return;
    }
    hanoi(towers, n - 1, from, aux, to);
    move_disk(towers, from, to, n);
    hanoi(towers, n - 1, aux, to, from);
}

// Function to get user input for the number of disks
int get_n()
{
    int n;
    do {
        printf("Enter the number of disks (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > MAX_DISKS);
    return n;
}

// Main function
int main()
{
    srand(time(NULL));
    int n = get_n();
    int towers[3][MAX_DISKS] = {{-1}};
    int from = 0, to = 2;
    int i, j;

    // Initialize the towers with n disks
    for (i = n - 1; i >= 0; i--) {
        towers[0][i] = i + 1;
    }

    // Solve the Tower of Hanoi problem
    hanoi(towers, n, from, to, 1);

    // Print the final state of the towers
    print_towers(towers, n);

    return 0;
}