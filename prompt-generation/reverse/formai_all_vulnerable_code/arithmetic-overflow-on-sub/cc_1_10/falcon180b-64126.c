//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 // number of disks

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int choice;
    char from_rod, to_rod, aux_rod;
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    srand(time(0));
    choice = rand() % 3; // randomly choose a starting rod

    if (choice == 0) {
        from_rod = 'A';
        to_rod = 'C';
        aux_rod = 'B';
    } else if (choice == 1) {
        from_rod = 'B';
        to_rod = 'A';
        aux_rod = 'C';
    } else {
        from_rod = 'C';
        to_rod = 'B';
        aux_rod = 'A';
    }

    printf("Starting configuration:\n");
    for (int i = n; i >= 1; i--) {
        printf("%c ", from_rod);
    }
    printf("\n");

    tower_of_hanoi(n, from_rod, to_rod, aux_rod);

    return 0;
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }

    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}