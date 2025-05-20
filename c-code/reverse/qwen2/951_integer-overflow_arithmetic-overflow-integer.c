#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void moveDisk(char fromPeg, char toPeg) {
    printf("Move disk from %c to %c\n", fromPeg, toPeg);
}

void towerOfHanoi(int n, char fromPeg, char toPeg, char auxPeg, int *moves) {
    if (n == 1) {
        moveDisk(fromPeg, toPeg);
        (*moves)++;
        return;
    }
    towerOfHanoi(n - 1, fromPeg, auxPeg, toPeg, moves);
    moveDisk(fromPeg, toPeg);
    (*moves)++;
    towerOfHanoi(n - 1, auxPeg, toPeg, fromPeg, moves);
}

int main() {
    int n, moves = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of disks must be positive.\n");
        return 1;
    }

    towerOfHanoi(n, 'A', 'C', 'B', &moves);
    printf("Total number of moves: %d\n", moves);

    return 0;
}
