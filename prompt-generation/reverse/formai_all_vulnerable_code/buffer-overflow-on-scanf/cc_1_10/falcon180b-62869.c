//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the current state of the tower
void print_tower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("Move disk %c from %c to %c\n", n, from, to);
}

// Function to check if a move is valid
int is_valid_move(int n, char from, char to)
{
    if (from == 'A' || from == 'C') {
        if (to == 'B' && from!= 'A' || to == 'C' && from!= 'C') {
            return 1;
        }
    } else if (from == 'B') {
        if (to == 'A' || to == 'C') {
            return 1;
        }
    }
    return 0;
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    print_tower(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 0;
    }
    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}