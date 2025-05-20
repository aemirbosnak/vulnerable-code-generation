//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 1000

int main() {
    int num_disks;
    int source, destination, temp;
    int *tower;
    int moves = 0;
    int start_time, end_time;

    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks do you want to play with? (1-1000) ");
    scanf("%d", &num_disks);

    tower = (int *) malloc(num_disks * sizeof(int));
    if (tower == NULL) {
        printf("Error: Could not allocate memory for tower.\n");
        return 1;
    }

    printf("Initializing tower...\n");
    for (int i = num_disks - 1; i >= 0; i--) {
        tower[i] = i;
    }

    source = num_disks - 1;
    destination = 0;
    temp = 0;

    printf("Starting game...\n");
    start_time = clock();

    while (source!= destination) {
        if (source > destination) {
            temp = source;
            source = destination;
            destination = temp;
        }

        if (source > destination + 1) {
            tower[destination + 1] = tower[source];
            moves++;
            source--;
            destination++;
        } else {
            tower[destination] = tower[source];
            moves++;
            source--;
            destination--;
        }
    }

    end_time = clock();

    printf("\nCongratulations! You solved the Tower of Hanoi in %d moves and %d seconds.\n", moves, (end_time - start_time) / CLOCKS_PER_SEC);

    free(tower);
    return 0;
}