#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from_rod, char to_rod, char aux_rod);

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}

void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n > 0) {
        hanoi(n - 1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}
