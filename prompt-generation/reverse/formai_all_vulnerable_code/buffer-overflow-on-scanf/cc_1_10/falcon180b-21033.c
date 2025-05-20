//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of disks
void print_disks(char from_rod, char to_rod, char aux_rod, int n) {
    printf("\nCurrent state of disks:\n");
    printf("From rod %c:\n", from_rod);
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    printf("To rod %c:\n", to_rod);

    if (n > 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", i);
        }
    } else {
        printf("Empty\n");
    }

    printf("Auxiliary rod %c:\n", aux_rod);
}

// Function to move n disks from from_rod to to_rod using aux_rod as auxiliary rod
void tower_of_hanoi(char from_rod, char to_rod, char aux_rod, int n) {
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(from_rod, aux_rod, to_rod, n - 1);

    printf("\nMove disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    tower_of_hanoi(aux_rod, to_rod, from_rod, n - 1);
}

// Function to get user input for number of disks
int get_num_disks() {
    int num_disks;
    do {
        printf("\nEnter the number of disks (1 to %d): ", MAX_DISKS);
        scanf("%d", &num_disks);
    } while (num_disks < 1 || num_disks > MAX_DISKS);

    return num_disks;
}

// Main function
int main() {
    srand(time(NULL));

    int num_disks = get_num_disks();
    char from_rod = 'A';
    char to_rod = 'C';
    char aux_rod = 'B';

    printf("\nTower of Hanoi Problem with %d disks\n", num_disks);

    tower_of_hanoi(from_rod, to_rod, aux_rod, num_disks);

    return 0;
}