//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    int top = -1;
    if (n == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", fromRod, toRod);
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    printf("\nMove disk %d from rod %c to rod %c", n, fromRod, toRod);
    top = n - 1;
    towerOfHanoi(top, auxRod, toRod, fromRod);
}

void main() {
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    srand(time(NULL));
    int fromRod = rand() % 3;
    int toRod = rand() % 3;
    printf("\nRandomly selected rods are: ");
    switch (fromRod) {
        case 0:
            printf("A");
            break;
        case 1:
            printf("B");
            break;
        case 2:
            printf("C");
            break;
    }
    printf(" and ");
    switch (toRod) {
        case 0:
            printf("A");
            break;
        case 1:
            printf("B");
            break;
        case 2:
            printf("C");
            break;
    }
    printf("\n\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n\n");
}