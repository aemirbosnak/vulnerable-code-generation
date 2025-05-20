//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int A[], int B[], int C[]) {
    printf("Move disk %d from ", n);
    if (n > 0)
        printf("tower A ");
    else
        printf("tower C ");
    if (n % 2 == 0)
        printf("to tower B\n");
    else
        printf("to tower C\n");
}

// Function to check if the move is valid or not
int is_valid_move(int n, int from, int to, int A[], int B[], int C[]) {
    if (from == to || from == -1 || to == -1)
        return 0;
    if (n == 1) {
        A[to] = 1;
        B[0] = 0;
        C[0] = 0;
        return 1;
    }
    if (n % 2 == 0) {
        A[to] = A[from] + A[to];
        B[0] = 0;
        C[0] = A[from];
        return 1;
    } else {
        A[to] = A[from] - A[to] + A[0];
        B[0] = 0;
        C[0] = A[from] - A[to] + A[0];
        return 1;
    }
}

// Function to move n disks from from to to
void move_disks(int n, int from, int to, int A[], int B[], int C[]) {
    if (is_valid_move(n, from, to, A, B, C)) {
        print_towers(n, A, B, C);
        system("sleep 0.5s");
    } else
        printf("Invalid move\n");
}

// Function to solve the Tower of Hanoi problem recursively
void tower_of_hanoi(int n, int A[], int B[], int C[]) {
    if (n == 1) {
        move_disks(1, 0, 2, A, B, C);
        return;
    }
    tower_of_hanoi(n - 1, A, C, B);
    move_disks(n, 0, 2, A, B, C);
    tower_of_hanoi(n - 1, B, A, C);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1 || n > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 0;
    }
    int A[MAX_DISKS], B[MAX_DISKS], C[MAX_DISKS];
    for (int i = n; i >= 1; i--)
        A[i] = 0;
    A[0] = 1;
    system("clear");
    tower_of_hanoi(n, A, C, B);
    return 0;
}