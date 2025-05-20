//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the disks on the rod
void print_disks(int rod, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("->%d", rod);
        else
            printf("%d->", rod);
    }
    printf("\n");
}

// Function to move the disk from source to destination
void move_disk(int n, char src, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", src, dest);
        return;
    }
    move_disk(n - 1, src, aux, dest);
    printf("Move disk %d from rod %c to rod %c\n", n, src, dest);
    move_disk(n - 1, aux, dest, src);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, char src, char dest, char aux) {
    if (n == 1) {
        move_disk(n, src, dest, aux);
        return;
    }
    tower_of_hanoi(n - 1, src, aux, dest);
    move_disk(n, src, dest, aux);
    tower_of_hanoi(n - 1, aux, dest, src);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX) {
        printf("Invalid number of disks.\n");
        return 0;
    }
    printf("The initial state of the towers:\n");
    print_disks(1, n);
    printf("Move %d disks from rod 1 to rod 3\n", n);
    tower_of_hanoi(n, '1', '3', '2');
    printf("The final state of the towers:\n");
    print_disks(1, n);
    return 0;
}