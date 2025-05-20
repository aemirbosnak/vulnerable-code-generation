//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to print the towers
void print_towers(int n, int A[], int C[], int B[])
{
    int i;
    for (i = 0; i <= n; i++) {
        printf(" ");
    }
    printf("\n");
    for (i = n; i >= 1; i--) {
        printf(" ");
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        printf("*\n");
    }
}

// Function to move the disk from one tower to another
void move_disk(int n, int A[], int C[], int B[], int from_tower, int to_tower)
{
    if (n == 1) {
        printf("Move disk 1 from tower %d to tower %d\n", from_tower, to_tower);
        A[to_tower] = 1;
        A[from_tower] = 0;
        return;
    }
    move_disk(n - 1, A, C, B, from_tower, to_tower);
    printf("Move disk %d from tower %d to tower %d\n", n, from_tower, to_tower);
    A[to_tower] += A[from_tower];
    A[from_tower] = 0;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int n, int A[], int C[], int B[], int from_tower, int to_tower)
{
    if (n == 1) {
        move_disk(n, A, C, B, from_tower, to_tower);
        return;
    }
    tower_of_hanoi(n - 1, A, C, B, from_tower, to_tower);
    tower_of_hanoi(1, A, B, C, to_tower, from_tower);
    tower_of_hanoi(n - 1, B, A, C, from_tower, to_tower);
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int A[MAX], B[MAX], C[MAX];
    printf("Initial configuration:\n");
    for (int i = n; i >= 1; i--) {
        A[0] += i;
        printf("Move disk %d from tower A to tower C\n", i);
    }
    printf("\n");
    print_towers(n, A, C, B);
    printf("Solved configuration:\n");
    tower_of_hanoi(n, A, C, B, 0, 2);
    print_towers(n, A, C, B);
    return 0;
}