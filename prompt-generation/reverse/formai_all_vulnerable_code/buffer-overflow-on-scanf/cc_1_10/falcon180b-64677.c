//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 10

/* Function to print the current state of the towers of Hanoi problem */
void print_towers(int n, char from, char to, char aux) {
    int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%c ", 'A');
        } else {
            printf("%c ", 'D');
        }
    }
    printf(" %c ", from);
    printf(" %c ", to);
    printf(" %c ", aux);
    printf("\n");
}

/* Function to move n disks from source to destination using the towers of Hanoi problem */
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

/* Function to read input from the user and solve the towers of Hanoi problem */
void solve_hanoi() {
    int n;
    char from, to, aux;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Enter the initial tower: ");
    scanf(" %c", &from);
    printf("Enter the final tower: ");
    scanf(" %c", &to);
    printf("Enter the auxiliary tower: ");
    scanf(" %c", &aux);
    printf("The initial state of the towers is:\n");
    print_towers(n, from, to, aux);
    hanoi(n, from, to, aux);
    printf("The final state of the towers is:\n");
    print_towers(n, from, to, aux);
}

/* Main function */
int main() {
    solve_hanoi();
    return 0;
}