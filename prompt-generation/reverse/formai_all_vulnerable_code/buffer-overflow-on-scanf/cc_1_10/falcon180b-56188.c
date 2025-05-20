//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 30

// Function to print the towers
void print_towers(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", from);
        from += to - aux;
    }
    printf("\n");
}

// Function to check if move is valid
int is_valid_move(int n, char from, char to, char aux)
{
    if (from < 0 || from >= n || to < 0 || to >= n || aux < 0 || aux >= n) {
        return 0;
    }
    if (to == aux || from == to) {
        return 0;
    }
    return 1;
}

// Function to move disk from one tower to another
void move_disk(int n, char from, char to, char aux)
{
    printf("Move disk %d from %c to %c\n", n, from, to);
    from += to - aux;
}

// Function to solve the tower of hanoi problem
void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        move_disk(n, from, to, aux);
        return;
    }
    tower_of_hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    tower_of_hanoi(n - 1, aux, to, from);
}

// Main function
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    printf("\n");
    return 0;
}