#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0 || UCHAR_MAX < n * 3 + 2) {
        printf("Invalid disk count. Please enter a number between 1 and %d.\n", UCHAR_MAX / 3 - 2);
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
