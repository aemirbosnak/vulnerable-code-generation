//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
/* 
This is a modular approach to the Tower of Hanoi problem in C.
The program consists of three functions:
1. void display_tower(int n, int from_rod, int to_rod, int aux_rod)
2. void move_tower(int n, int from_rod, int to_rod, int aux_rod)
3. void hanoi(int n, int from_rod, int to_rod, int aux_rod)

The main function calls the hanoi function with the required parameters.
*/

#include <stdio.h>

// Function to display the current state of the towers
void display_tower(int n, int from_rod, int to_rod, int aux_rod) {
    int i;
    for(i=n; i>=1; i--) {
        printf(" ");
    }
    printf("\n");
    for(i=1; i<=n; i++) {
        if(i == n) {
            printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

// Function to move n disks from from_rod to to_rod using aux_rod
void move_tower(int n, int from_rod, int to_rod, int aux_rod) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    move_tower(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    move_tower(n-1, aux_rod, to_rod, from_rod);
}

// Function to solve the Tower of Hanoi problem
void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
    if(n == 1) {
        move_tower(n, from_rod, to_rod, aux_rod);
        return;
    }
    hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    hanoi(n-1, aux_rod, to_rod, from_rod);
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Solving Tower of Hanoi problem for %d disks...\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}