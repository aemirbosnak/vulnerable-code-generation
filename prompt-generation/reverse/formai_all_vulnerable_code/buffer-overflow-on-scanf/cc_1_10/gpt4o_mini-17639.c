//GPT-4o-mini DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Defining the maximum number of disks
#define MAX_DISKS 64

// Function to print the current state of the towers
void printTowers(int numberOfDisks, int source[], int target[], int auxiliary[], int size) {
    printf("\nCurrent state of towers after a disaster:\n");
    printf("Source Tower: ");
    for(int i = 0; i < size; i++) {
        if(source[i] != 0) printf("%d ", source[i]);
    }
    printf("\nTarget Tower: ");
    for(int i = 0; i < size; i++) {
        if(target[i] != 0) printf("%d ", target[i]);
    }
    printf("\nAuxiliary Tower: ");
    for(int i = 0; i < size; i++) {
        if(auxiliary[i] != 0) printf("%d ", auxiliary[i]);
    }
    printf("\n");
}

// Recursive function to solve the Tower of Hanoi
void towerOfHanoi(int n, int source[], int target[], int auxiliary[], int size, int *sourceTop, int *targetTop, int *auxTop) {
    if (n == 1) {
        // Move disk from source to target
        target[(*targetTop)++] = source[--(*sourceTop)];
        printTowers(n, source, target, auxiliary, size);
        return;
    }

    // Move n-1 disks from source to auxiliary
    towerOfHanoi(n - 1, source, auxiliary, target, size, sourceTop, auxTop, targetTop);
    // Move the last disk from source to target
    target[(*targetTop)++] = source[--(*sourceTop)];
    printTowers(n, source, target, auxiliary, size);
    // Move the n-1 disks from auxiliary to target
    towerOfHanoi(n - 1, auxiliary, target, source, size, auxTop, targetTop, sourceTop);
}

// Function to initialize the game
void initializeTowers(int numberOfDisks, int source[], int *sourceTop) {
    for (int i = numberOfDisks; i >= 1; i--) {
        source[(*sourceTop)++] = i;
    }
}

// Function to check if the game is solvable based on the number of disks
int isGameSolvable(int numberOfDisks) {
    return (numberOfDisks % 2 == 0);
}

int main() {
    int numberOfDisks, source[MAX_DISKS] = {0}, target[MAX_DISKS] = {0}, auxiliary[MAX_DISKS] = {0};
    int sourceTop = 0, targetTop = 0, auxTop = 0;

    // Welcome message in a post-apocalyptic tone
    printf("Welcome to the Tower of Hanoi: Apocalypse Edition\n");
    printf("In a world where survival depends on strategy, your task is clear...\n");
    printf("How many disks shall you wager to escape this dystopian nightmare? (1-64): ");
    scanf("%d", &numberOfDisks);

    // Input validation
    while (numberOfDisks < 1 || numberOfDisks > MAX_DISKS) {
        printf("Invalid number of disks, please choose again (1-64): ");
        scanf("%d", &numberOfDisks);
    }

    initializeTowers(numberOfDisks, source, &sourceTop);

    if (isGameSolvable(numberOfDisks)) {
        printf("The game is solvable. Begin your efforts to reclaim the towers...\n");
        printTowers(numberOfDisks, source, target, auxiliary, numberOfDisks);
        towerOfHanoi(numberOfDisks, source, target, auxiliary, numberOfDisks, &sourceTop, &targetTop, &auxTop);
        printf("You have successfully moved all disks to the target tower!\n");
    } else {
        printf("In this world, with an odd number of disks, survival is not possible.\n");
    }
    
    return 0;
}