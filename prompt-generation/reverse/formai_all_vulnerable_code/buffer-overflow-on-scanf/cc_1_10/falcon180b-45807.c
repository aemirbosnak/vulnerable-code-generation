//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100

void print_disks(int disks[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", disks[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Get the number of disks from user input
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Initialize the disks with random values
    int disks[MAX_DISKS];
    for (int i = 0; i < n; i++) {
        disks[i] = rand() % (MAX_DISKS - 1) + 1;
    }
    
    // Print the initial state of the disks
    printf("Initial state:\n");
    print_disks(disks, n);
    
    // Move the disks from the start peg to the end peg
    int start_peg = 0;
    int end_peg = 2;
    int aux_peg = 1;
    int moves = 0;
    time_t start_time = time(NULL);
    do {
        printf("Move %d: ", moves);
        print_disks(disks, n);
        int disk = disks[start_peg];
        disks[start_peg] = 0;
        moves++;
        if (moves % 2 == 0) {
            disks[end_peg] = disk;
            end_peg++;
        } else {
            disks[aux_peg] = disk;
            aux_peg++;
        }
        start_peg++;
        if (start_peg >= end_peg) {
            start_peg = 0;
        }
    } while (end_peg!= 2);
    
    // Print the final state of the disks and the number of moves
    printf("\nFinal state:\n");
    print_disks(disks, n);
    printf("Number of moves: %d\n", moves);
    
    // Print the time taken to solve the problem
    time_t end_time = time(NULL);
    printf("Time taken: %ld seconds\n", end_time - start_time);
    
    return 0;
}