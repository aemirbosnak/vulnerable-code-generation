//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

// Function to print the current state of the towers
void print_towers(int n, int a, int b, int c) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == a) {
            printf("A: ");
        } else if (i == b) {
            printf("B: ");
        } else if (i == c) {
            printf("C: ");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to move n disks from source to destination using buffer
void hanoi(int n, int a, int b, int c) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("Move disk %d from %c to %c\n", n, a, c);
    hanoi(n - 1, b, a, c);
}

// Function to generate random tower configuration
void generate_tower(int n, int a, int b, int c) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        a = (a + 2 * b - c) % 3;
        b = (b + 2 * c - a) % 3;
        c = (c + 2 * a - b) % 3;
    }
}

int main() {
    int n, a, b, c;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    a = 0;
    b = 1;
    c = 2;
    srand(time(NULL));
    generate_tower(n, a, b, c);
    printf("Initial configuration:\n");
    print_towers(n, a, b, c);
    printf("Solved configuration:\n");
    hanoi(n, a, b, c);
    return 0;
}