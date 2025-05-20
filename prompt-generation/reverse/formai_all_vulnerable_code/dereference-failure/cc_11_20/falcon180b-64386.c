//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_PILES 10
#define MAX_DISKS 10
#define MOVE_DELAY 100000

int main() {
    int num_disks, num_piles = 3, source_pile = 0, dest_pile = 2, top_pile = 0;
    int *piles = malloc(MAX_PILES * sizeof(int)); // Allocate memory for the piles
    for (int i = 0; i < MAX_PILES; i++) {
        piles[i] = 0;
    }
    srand(time(NULL)); // Seed the random number generator
    num_disks = rand() % (MAX_DISKS - 1) + 1; // Generate a random number of disks
    printf("Number of disks: %d\n", num_disks);
    for (int i = num_disks - 1; i >= 0; i--) { // Initialize the piles with the disks
        piles[0]++;
        printf("Disk %d placed on pile %d\n", i + 1, 0);
        usleep(MOVE_DELAY); // Add a delay to simulate the movement of the disk
    }
    system("clear"); // Clear the console
    printf("Initial configuration:\n");
    for (int i = 0; i < num_piles; i++) {
        printf("Pile %d: ", i + 1);
        for (int j = 0; j < piles[i]; j++) {
            printf("X ");
        }
        printf("\n");
    }
    while (top_pile!= dest_pile) { // Move the disks from source_pile to dest_pile
        if (piles[top_pile] > 0) {
            if (piles[top_pile] == 1) {
                printf("Moving disk %d from pile %d to pile %d\n", num_disks - piles[top_pile], top_pile, dest_pile);
            } else {
                printf("Moving %d disks from pile %d to pile %d\n", piles[top_pile], top_pile, dest_pile);
            }
            for (int i = piles[top_pile] - 1; i >= 1; i--) {
                piles[dest_pile]++;
                printf("Disk %d placed on pile %d\n", num_disks - i, dest_pile);
                usleep(MOVE_DELAY);
            }
            piles[top_pile]--;
            printf("Disk %d removed from pile %d\n", num_disks - piles[top_pile], top_pile);
            usleep(MOVE_DELAY);
        }
        top_pile = (top_pile + 1) % num_piles; // Move to the next pile
        system("clear"); // Clear the console
        printf("Current configuration:\n");
        for (int i = 0; i < num_piles; i++) {
            printf("Pile %d: ", i + 1);
            for (int j = 0; j < piles[i]; j++) {
                printf("X ");
            }
            printf("\n");
        }
    }
    printf("Congratulations! You solved the Tower of Hanoi problem in %d moves.\n", num_disks - 1);
    return 0;
}