//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to print the tower of Hanoi
void print_tower(int n, char from, char to, char aux)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("%c ", 'A' + i);
        else if (i < n - 1 && from == 'A')
            printf("%c ", 'A' + i);
        else
            printf(" ");
    }

    printf("\n");
}

// Function to move the disk from from_rod to to_rod
void move_disk(char from_rod, char to_rod, char aux_rod, int n)
{
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }

    move_disk(from_rod, aux_rod, to_rod, n - 1);

    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
}

// Function to play the tower of Hanoi game
void play_game(int n)
{
    int i;
    char from_rod, to_rod, aux_rod;

    printf("\nWelcome to the Tower of Hanoi game!\n");

    srand(time(0));

    from_rod = 'A';
    to_rod = 'C';
    aux_rod = 'B';

    for (i = n; i >= 1; i--) {
        printf("\n\nLevel %d: ", i);
        print_tower(i, from_rod, to_rod, aux_rod);
        move_disk(from_rod, to_rod, aux_rod, i);
    }

    printf("\n\nCongratulations! You have completed the Tower of Hanoi game.\n");
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of disks.\n");
        return 0;
    }

    play_game(n);

    return 0;
}