//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Function to print the solution
void print_solution(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    else
    {
        print_solution(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        print_solution(n - 1, aux_rod, to_rod, from_rod);
    }
}

// Function to check if a move is valid
int is_valid_move(int n, int from_rod, int to_rod, int aux_rod)
{
    if (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod)
        return 0;
    if (from_rod > to_rod && (from_rod - to_rod)!= aux_rod)
        return 0;
    if (from_rod < to_rod && (to_rod - from_rod)!= aux_rod)
        return 0;
    return 1;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The solution for %d disks is:\n", n);
    print_solution(n, 'A', 'C', 'B');
    printf("\n");
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}