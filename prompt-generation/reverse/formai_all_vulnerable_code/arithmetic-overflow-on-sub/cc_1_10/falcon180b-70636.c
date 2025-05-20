//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void print_tower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf(" ");
    }
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to, char aux)
{
    // Base case
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return 1;
    }

    // Check if the move is valid
    if (from == to || from == aux) {
        return 0;
    }

    // Recursive case
    int is_valid = is_valid_move(n - 1, from, aux, to);

    if (is_valid == 1) {
        print_tower(n, from, to, aux);
        is_valid_move(n - 1, aux, to, from);
    }

    return is_valid;
}

// Main function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux)
{
    is_valid_move(n, from, to, aux);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}