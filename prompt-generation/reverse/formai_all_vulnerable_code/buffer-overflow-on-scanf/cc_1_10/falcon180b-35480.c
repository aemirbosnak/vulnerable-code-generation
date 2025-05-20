//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY_TIME 100000

// Function to print the current state of the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    printf("Move disk %d from %c to %c:\n", n, from, to);
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c <- %d\n", to, n);
        } else {
            printf("%c <- %c\n", to, (char) (i + 'A'));
        }
        to = (char) (i + 'A');
    }
}

// Function to move n disks from from_rod to to_rod using aux_rod
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    print_towers(n, from_rod, to_rod, aux_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    srand(time(NULL));
    char from_rod = (char) (rand() % 3 + 'A');
    char to_rod = (char) (rand() % 3 + 'A');
    char aux_rod = (char) (rand() % 3 + 'A');
    while (from_rod == to_rod || from_rod == aux_rod || to_rod == aux_rod) {
        from_rod = (char) (rand() % 3 + 'A');
        to_rod = (char) (rand() % 3 + 'A');
        aux_rod = (char) (rand() % 3 + 'A');
    }
    printf("Initial state:\n");
    print_towers(n, from_rod, to_rod, aux_rod);
    hanoi(n, from_rod, to_rod, aux_rod);
    printf("\n");
    return 0;
}