//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// function to print the disks in a tower
void printTower(int tower[], int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

// function to check if a move is valid or not
int isValid(int tower[], int n, int from, int to) {
    // check if the disk can be moved
    if(from < 0 || from >= n || to < 0 || to >= n || from == to) {
        return 0;
    }

    // check if there is a larger disk on top of the disk to be moved
    if(tower[from] > tower[to]) {
        return 0;
    }

    return 1;
}

// function to move a disk from one tower to another
void moveDisk(int tower[], int n, int from, int to) {
    // move the disk
    tower[to] = tower[from];

    // remove the disk from the original tower
    tower[from] = 0;
}

// function to solve the Tower of Hanoi problem
void towerOfHanoi(int tower[], int n, int from, int to, int aux) {
    // base case
    if(n == 1) {
        moveDisk(tower, n, from, to);
        return;
    }

    // recursive case
    towerOfHanoi(tower, n-1, from, aux, to);
    moveDisk(tower, n, from, to);
    towerOfHanoi(tower, n-1, aux, to, from);
}

// main function
int main() {
    int n, i;

    // get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // initialize the towers
    int towerA[MAX], towerB[MAX], towerC[MAX];
    for(i=n-1; i>=0; i--) {
        towerA[i] = i+1;
    }

    // solve the Tower of Hanoi problem
    towerOfHanoi(towerA, n, 0, 2, 1);

    // print the towers
    printf("Tower A: ");
    printTower(towerA, n);
    printf("Tower B: ");
    printTower(towerB, n);
    printf("Tower C: ");
    printTower(towerC, n);

    return 0;
}