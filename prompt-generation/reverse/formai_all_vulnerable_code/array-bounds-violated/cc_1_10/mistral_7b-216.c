//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

// Define constants
#define DISKS_COUNT 3
#define SOURCE_TOWER 'A'
#define DEST_TOWER 'C'
#define AUX_TOWER 'B'
#define DISK_SIZE 10

// Define structures and functions
typedef struct {
    char tower_letter;
    int disks_count;
} tower_t;

void hanoi(int disks_count, char source_tower, char dest_tower, char aux_tower);
void print_towers(tower_t towers[3]);
void move_disk(int disks_count, char source_tower, char dest_tower, char aux_tower);

// Initialize global variables
tower_t towers[3];

int main() {
    // Initialize towers
    towers[SOURCE_TOWER].tower_letter = SOURCE_TOWER;
    towers[SOURCE_TOWER].disks_count = DISKS_COUNT;
    towers[DEST_TOWER].tower_letter = DEST_TOWER;
    towers[AUX_TOWER].tower_letter = AUX_TOWER;
    towers[SOURCE_TOWER].disks_count = 0;
    towers[DEST_TOWER].disks_count = 0;
    towers[AUX_TOWER].disks_count = 0;

    // Call the Hanoi function
    hanoi(DISKS_COUNT, SOURCE_TOWER, DEST_TOWER, AUX_TOWER);

    // Print the final state of the towers
    print_towers(towers);

    return 0;
}

// Implement the Hanoi recursive function
void hanoi(int disks_count, char source_tower, char dest_tower, char aux_tower) {
    if (disks_count > 0) {
        // Recursive call for moving the top disk
        move_disk(disks_count - 1, source_tower, aux_tower, dest_tower);

        // Move the disk from the source tower to the destination tower
        move_disk(1, source_tower, dest_tower, aux_tower);

        // Recursive call for moving the remaining disks
        hanoi(disks_count - 1, aux_tower, dest_tower, source_tower);
    }
}

// Implement the move_disk function
void move_disk(int disk_size, char source_tower, char dest_tower, char aux_tower) {
    if (towers[source_tower].disks_count >= disk_size && towers[dest_tower].disks_count == 0) {
        printf("Move disk %d from tower %c to tower %c\n", disk_size, source_tower, dest_tower);

        towers[source_tower].disks_count--;
        towers[dest_tower].disks_count++;

        usleep(100000); // Sleep for a short time to simulate disk movement
    } else {
        printf("Cannot move disk %d from tower %c to tower %c\n", disk_size, source_tower, dest_tower);
    }
}

// Implement the print_towers function
void print_towers(tower_t towers[3]) {
    printf("\nCurrent state of the towers:\n");
    for (int i = 0; i < 3; i++) {
        printf("Tower %c: ", towers[i].tower_letter);
        for (int j = 0; j < towers[i].disks_count; j++) {
            printf("Disk %d ", DISKS_COUNT - j);
        }
        printf("\n");
    }
}