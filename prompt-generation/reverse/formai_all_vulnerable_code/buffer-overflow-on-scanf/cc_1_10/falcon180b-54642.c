//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

// Function prototypes
void move_tower(int n, char from_rod, char to_rod, char aux_rod);
void print_tower(int n, char rod);
void swap(char *a, char *b);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Starting the Tower of Hanoi problem with %d disks...\n", n);
    srand(time(NULL));
    move_tower(n, 'A', 'C', 'B');

    printf("\nTower of Hanoi problem solved!\n");
    return 0;
}

// Function to move n disks from from_rod to to_rod using aux_rod
void move_tower(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    move_tower(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    move_tower(n - 1, aux_rod, to_rod, from_rod);
}

// Function to print the current state of the rods
void print_tower(int n, char rod) {
    int i;
    for (i = n; i >= 1; i--) {
        printf("Disk %d is on rod %c\n", i, rod);
    }
}

// Function to swap the values of two variables
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}