//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

// Function to print the current state of the towers
void print_towers(int n, int a[], int b[], int c[]) {
    printf("Tower A: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Tower B: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("Tower C: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", c[i]);
    }
    printf("\n");
}

// Function to move n disks from source to destination using auxiliary
void hanoi(int n, char source, char dest, char aux) {
    int a[MAX_DISKS], b[MAX_DISKS], c[MAX_DISKS];

    // Initialize the towers
    for(int i=n-1; i>=0; i--) {
        a[i] = i+1;
    }

    // Move n disks from source to dest
    while(n>0) {
        if(n==1) {
            printf("Moving disk 1 from %c to %c\n", source, dest);
            b[0] = a[0];
            a[0] = 0;
            n--;
        } else {
            printf("Moving %d disks from %c to %c using %c\n", n, source, dest, aux);
            hanoi(n-1, source, aux, dest);
            printf("Moving disk %d from %c to %c\n", n, source, dest);
            b[n-1] = a[n-1];
            a[n-1] = 0;
            n--;
        }

        // Print the current state of the towers
        print_towers(n, a, b, c);
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Get the number of disks from user input
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the hanoi function to solve the Tower of Hanoi problem
    hanoi(n, 'A', 'C', 'B');

    return 0;
}