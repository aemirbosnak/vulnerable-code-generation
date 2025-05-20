//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <math.h>
#define MAX_NODES 10
#define PI 3.14159265359

// function to solve the Tower of Hanoi problem recursively
void hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", from_rod, to_rod);
    }
    else {
        // move n-1 disks from rod 1 to rod 3
        hanoi(n - 1, from_rod, aux_rod, to_rod);
        
        // move disk n from rod 1 to rod 2
        printf("Move disk %d from rod %c to rod %c.\n", n, from_rod, to_rod);
        
        // move n-1 disks from rod 2 to rod 3
        hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

// function to print the solution to the Tower of Hanoi problem using polar coordinates
void hanoi_polar(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", from_rod, to_rod);
    }
    else {
        // move n-1 disks from rod 1 to rod 3
        hanoi_polar(n - 1, from_rod, aux_rod, to_rod);
        
        // move disk n from rod 1 to rod 2
        printf("Move disk %d from rod %c to rod %c.\n", n, from_rod, to_rod);
        
        // move n-1 disks from rod 2 to rod 3
        hanoi_polar(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int n;
    char from_rod, to_rod, aux_rod;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the initial rod: ");
    scanf(" %c", &from_rod);
    printf("Enter the target rod: ");
    scanf(" %c", &to_rod);
    printf("Enter the auxiliary rod: ");
    scanf(" %c", &aux_rod);
    
    // solve the Tower of Hanoi problem using polar coordinates
    hanoi_polar(n, from_rod, to_rod, aux_rod);
    
    return 0;
}