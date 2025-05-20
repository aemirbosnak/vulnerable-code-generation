#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || n > INT_MAX / 2) {
        printf("Invalid number of disks. Please enter a number between 1 and %d.\n", INT_MAX / 2);
        return 1;
    }

    char rods[3] = {'A', 'B', 'C'};
    hanoi(n, rods[0], rods[2], rods[1]);

    return 0;
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}
