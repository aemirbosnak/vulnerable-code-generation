//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the towers
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    printf("   %c\n", from);
    printf("  ");
    for (i = 0; i < n - 1; ++i) {
        printf("%c ", 'A' + i);
    }
    printf("%c\n", to);
    printf("   %c\n", aux);
}

// Function to check if the move is valid
int is_valid_move(int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }
    return 1;
}

// Function to move the disk from source to destination
void move_disk(int n, int from, int to, char aux) {
    if (from > to) {
        move_disk(n, from - 1, aux, to);
    }
    else if (from < to) {
        printf("Move disk %d from %c to %c\n", n, 'A' + from, 'A' + to);
        printf("   %c\n", 'A' + from);
        printf("  ");
        for (int i = 0; i < n - 1; ++i) {
            printf("%c ", 'A' + i);
        }
        printf("%c\n", 'A' + to);
        printf("   %c\n", aux);
    }
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        printf("   %c\n", from);
        printf("   %c\n", to);
        printf("   %c\n", aux);
        return;
    }
    hanoi(n - 1, from, aux, to);
    move_disk(n, from, to, aux);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}