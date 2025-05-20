//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int a, b, c;
    char ch;

    printf("Welcome to the Tower of Hanoi Multiplayer Game!\n");

    printf("Enter the number of disks you want to move (maximum is 5): ");
    scanf("%d", &a);

    b = 2 * a - 1;
    c = 3 - a;

    printf("Player 1 (Move disks from A to B):\n");
    printf("Enter the number of disks you want to move: ");
    scanf("%d", &a);

    if (a > b)
    {
        printf("Error: You cannot move that many disks.\n");
    }
    else
    {
        printf("Move %d disks from A to B.\n", a);
        b -= a;
    }

    printf("Player 2 (Move disks from C to A):\n");
    printf("Enter the number of disks you want to move: ");
    scanf("%d", &a);

    if (a > c)
    {
        printf("Error: You cannot move that many disks.\n");
    }
    else
    {
        printf("Move %d disks from C to A.\n", a);
        c -= a;
    }

    printf("Congratulations! You have moved all the disks.\n");

    return 0;
}