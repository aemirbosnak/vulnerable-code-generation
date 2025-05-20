//Code Llama-13B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define NUM_DISKS 10
#define NUM_RODS 3

// Structure to represent a disk
typedef struct {
    int id;
    int size;
} disk_t;

// Function to initialize a disk
void init_disk(disk_t *disk, int id, int size) {
    disk->id = id;
    disk->size = size;
}

// Function to print the disks on a rod
void print_rod(disk_t *rod, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", rod[i].id);
    }
    printf("\n");
}

// Function to move a disk from one rod to another
void move_disk(disk_t *from, disk_t *to, int size) {
    disk_t temp = from[size - 1];
    to[size - 1] = temp;
    from[size - 1].id = -1;
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int num_disks, disk_t *rods[NUM_RODS]) {
    int i, j;
    for (i = 0; i < num_disks; i++) {
        init_disk(&rods[0][i], i, i + 1);
    }
    printf("Initial state:\n");
    for (i = 0; i < NUM_RODS; i++) {
        print_rod(rods[i], num_disks);
    }
    printf("\n");
    for (i = 0; i < num_disks; i++) {
        for (j = 0; j < NUM_RODS; j++) {
            if (rods[j][i].id != -1) {
                int k = (j + 1) % NUM_RODS;
                move_disk(rods[j], rods[k], i);
                break;
            }
        }
    }
    printf("Final state:\n");
    for (i = 0; i < NUM_RODS; i++) {
        print_rod(rods[i], num_disks);
    }
}

int main() {
    disk_t *rods[NUM_RODS];
    for (int i = 0; i < NUM_RODS; i++) {
        rods[i] = (disk_t *)malloc(sizeof(disk_t) * NUM_DISKS);
        for (int j = 0; j < NUM_DISKS; j++) {
            init_disk(&rods[i][j], -1, 0);
        }
    }
    tower_of_hanoi(NUM_DISKS, rods);
    for (int i = 0; i < NUM_RODS; i++) {
        free(rods[i]);
    }
    return 0;
}