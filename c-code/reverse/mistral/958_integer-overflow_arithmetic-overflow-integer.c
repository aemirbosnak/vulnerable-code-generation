#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char from, char to, char aux);

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    char towers[3];
    towers[0] = 'A';
    towers[1] = 'B';
    towers[2] = 'C';

    hanoi(n, towers[0], towers[2], towers[1]);

    return 0;
}

void hanoi(int n, char from, char to, char aux) {
    if (n > 0) {
        hanoi(n - 1, from, aux, to);
        printf("\nMove disk %d from %c to %c", n, from, to);
        hanoi(n - 1, aux, to, from);
    }
}
