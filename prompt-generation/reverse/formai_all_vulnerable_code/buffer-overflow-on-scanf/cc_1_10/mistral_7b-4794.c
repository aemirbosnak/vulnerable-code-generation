//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DISKS 32
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void hanoi(int n, char from_peg, char to_peg, char aux_peg);

int main() {
    int num_disks;
    char source_peg, dest_peg, aux_peg;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks > MAX_DISKS || num_disks < 1) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    printf("Enter the source peg: ");
    scanf(" %c", &source_peg);
    source_peg = toupper(source_peg);

    printf("Enter the destination peg: ");
    scanf(" %c", &dest_peg);
    dest_peg = toupper(dest_peg);

    printf("Enter the auxiliary peg: ");
    scanf(" %c", &aux_peg);
    aux_peg = toupper(aux_peg);

    if (source_peg == dest_peg || source_peg == aux_peg || dest_peg == aux_peg) {
        printf("Invalid pegs.\n");
        return 1;
    }

    printf("Moving %d disks from peg %c to peg %c using peg %c.\n", num_disks, source_peg, dest_peg, aux_peg);

    hanoi(num_disks, source_peg, dest_peg, aux_peg);

    return 0;
}

void hanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n > 0) {
        hanoi(n - 1, from_peg, aux_peg, to_peg);
        printf("Move disk %d from peg %c to peg %c.\n", n, from_peg, to_peg);
        hanoi(n - 1, aux_peg, to_peg, from_peg);
    }
}