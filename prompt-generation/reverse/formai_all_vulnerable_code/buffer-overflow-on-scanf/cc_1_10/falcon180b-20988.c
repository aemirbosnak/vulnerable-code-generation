//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to print the disks in each rod
void print_rods(int n, int rod1[], int rod2[], int rod3[]) {
    printf("Rod 1: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", rod1[i]);
    }
    printf("\n");
    printf("Rod 2: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", rod2[i]);
    }
    printf("\n");
    printf("Rod 3: ");
    for(int i=n-1; i>=0; i--) {
        printf("%d ", rod3[i]);
    }
    printf("\n\n");
}

// Function to move n disks from rod1 to rod3 using rod2
void tower_of_hanoi(int n, int rod1[], int rod2[], int rod3[]) {
    if(n == 1) {
        printf("Move disk 1 from rod 1 to rod 3\n");
        rod3[0] = rod1[0];
        rod1[0] = 0;
        print_rods(n, rod1, rod2, rod3);
        return;
    }
    tower_of_hanoi(n-1, rod1, rod3, rod2);
    printf("Move disk %d from rod 1 to rod 3\n", n);
    rod3[n-1] = rod1[n-1];
    rod1[n-1] = 0;
    print_rods(n, rod1, rod2, rod3);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    int rod1[n], rod2[n], rod3[n];
    for(int i=0; i<n; i++) {
        rod1[i] = i+1;
    }
    printf("Initial configuration:\n");
    print_rods(n, rod1, rod2, rod3);
    tower_of_hanoi(n, rod1, rod2, rod3);
    return 0;
}