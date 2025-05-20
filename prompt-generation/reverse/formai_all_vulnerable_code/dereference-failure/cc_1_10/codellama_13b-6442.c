//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to represent the towers
typedef struct {
    int top;
    int count;
    int* disks;
} tower_t;

// Function to move a disk from one tower to another
void move_disk(tower_t* from, tower_t* to, tower_t* spare) {
    if (from->count == 0 || to->count == 0) {
        printf("Invalid move\n");
        return;
    }

    // Move the top disk from the source tower to the spare tower
    to->disks[to->top++] = from->disks[from->top - 1];
    from->count--;

    // Move the top disk from the spare tower to the destination tower
    to->disks[to->top++] = spare->disks[spare->top - 1];
    spare->count--;
}

// Function to print the towers
void print_towers(tower_t* towers, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < towers[i].count; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char* argv[]) {
    // Create the towers
    tower_t towers[3];
    for (int i = 0; i < 3; i++) {
        towers[i].top = 0;
        towers[i].count = 0;
        towers[i].disks = malloc(sizeof(int) * 10);
    }

    // Add disks to the first tower
    for (int i = 0; i < 5; i++) {
        towers[0].disks[i] = i + 1;
        towers[0].count++;
    }

    // Move the disks from the first tower to the second tower
    for (int i = 0; i < 5; i++) {
        move_disk(&towers[0], &towers[1], &towers[2]);
    }

    // Move the disks from the second tower to the third tower
    for (int i = 0; i < 5; i++) {
        move_disk(&towers[1], &towers[2], &towers[0]);
    }

    // Print the towers
    print_towers(towers, 3);

    // Free the memory
    for (int i = 0; i < 3; i++) {
        free(towers[i].disks);
    }

    return 0;
}