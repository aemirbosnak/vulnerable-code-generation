//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 100000 // Delay in microseconds

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    printf("Move disk %d from %c to %c\n", n, from, to);
    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%c -> %c\n", from, to);
        else
            printf("%c -> %c\n", from, aux);
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        printf("%c -> %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    print_towers(n, from_rod, to_rod, aux_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    char from_rod, to_rod, aux_rod;

    // Get the number of disks from user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the towers
    printf("Initializing towers...\n");
    for (int i = n; i >= 1; i--) {
        printf("Disk %d placed on tower %c\n", i, 'A' + n - i);
        sleep(DELAY);
    }

    // Move the disks
    printf("\nMoving disks from tower %c to tower %c using tower %c...\n", 'A', 'C', 'B');
    hanoi(n, 'A', 'C', 'B');

    return 0;
}