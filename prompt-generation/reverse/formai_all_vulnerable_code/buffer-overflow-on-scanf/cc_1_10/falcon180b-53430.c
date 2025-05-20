//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void random_move(int n)
{
    srand(time(NULL));
    int move = rand() % (2 * n - 1);
    printf("Random move: Move disk %d from rod A to rod C\n", move);
    tower_of_hanoi(move, 'A', 'C', 'B');
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > N) {
        printf("Invalid number of disks\n");
        return 1;
    }

    printf("Solving the Tower of Hanoi problem with %d disks...\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');

    printf("\n");
    printf("Do you want to see a random move? (y/n): ");
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        random_move(n);
    }

    return 0;
}