//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the tower of hanoi
void print_tower(int n, char from, char to, char aux)
{
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("%c ", from);
        else if (i == n - 1)
            printf("%c ", to);
        else
            printf("%c ", aux);
    }
}

// Function to move the disk from source to destination using auxiliary
void move_disk(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("\nMove disk 1 from %c to %c", from, to);
        return;
    }

    move_disk(n - 1, from, aux, to);

    printf("\nMove disk %d from %c to %c", n, from, to);

    move_disk(n - 1, aux, to, from);
}

// Function to solve the tower of hanoi problem recursively
void tower_of_hanoi(int n, char from, char to, char aux)
{
    if (n == 1) {
        printf("\nMove disk 1 from %c to %c", from, to);
        return;
    }

    tower_of_hanoi(n - 1, from, aux, to);

    printf("\nMove disk %d from %c to %c", n, from, to);

    tower_of_hanoi(n - 1, aux, to, from);
}

// Main function to call the tower of hanoi function
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("\nInvalid number of disks");
        exit(0);
    }

    printf("\nTower of Hanoi\n");
    printf("--------------------\n");
    tower_of_hanoi(n, 'A', 'C', 'B');

    printf("\n\n");
    return 0;
}