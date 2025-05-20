//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to print the current state of the towers
void print_towers(int n, int a[], int c[], int b[]) {
    printf("Move %d: ", n);
    for (int i = 0; i <= n; i++) {
        if (i <= a[0])
            printf("A");
        else if (i <= b[0])
            printf("B");
        else
            printf("C");
    }
    printf("\n");
}

// Function to check if a move is valid
int is_valid_move(int n, int a[], int c[], int b[]) {
    if (a[0] == 0 && c[0] == 0 && b[0] == n - 1)
        return 1;
    else if (a[0] == n - 1 && b[0] == 0 && c[0] == 0)
        return 1;
    else
        return 0;
}

// Function to move a disk from one tower to another
void move_disk(int n, int a[], int c[], int b[]) {
    printf("Moving disk %d from %c to %c\n", n, 'A' + a[0], 'C' + c[0]);
    a[0]--;
    c[0]++;
}

// Function to recursively solve the Tower of Hanoi problem
void hanoi(int n, int a[], int c[], int b[]) {
    if (n == 1) {
        move_disk(n, a, c, b);
        return;
    }

    int k = rand() % (n - 1) + 1;
    hanoi(k, a, c, b);
    hanoi(n - k, c, b, a);
    hanoi(k, b, a, c);
}

int main() {
    int a[MAX], b[MAX], c[MAX];
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Initial state:\n");
    for (int i = n; i >= 1; i--) {
        a[0] = i;
        print_towers(1, a, c, b);
        move_disk(i, a, c, b);
    }

    srand(time(NULL));
    hanoi(n, a, c, b);

    printf("Final state:\n");
    print_towers(n, a, c, b);

    return 0;
}