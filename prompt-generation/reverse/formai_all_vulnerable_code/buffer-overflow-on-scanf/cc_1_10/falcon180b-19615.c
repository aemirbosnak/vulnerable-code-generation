//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_SNAPSHOTS 1000

typedef struct {
    size_t snapshot_index;
    size_t allocated_memory;
} MemorySnapshot;

MemorySnapshot memory_snapshots[MAX_MEMORY_SNAPSHOTS];
size_t num_memory_snapshots = 0;

void take_memory_snapshot() {
    if (num_memory_snapshots == MAX_MEMORY_SNAPSHOTS) {
        // Snapshot buffer is full, overwrite the oldest snapshot
        num_memory_snapshots = MAX_MEMORY_SNAPSHOTS;
        for (int i = 0; i < MAX_MEMORY_SNAPSHOTS; i++) {
            memory_snapshots[i].snapshot_index = i;
            memory_snapshots[i].allocated_memory = 0;
        }
    }

    size_t allocated_memory = malloc_usable_size(0);
    memory_snapshots[num_memory_snapshots].snapshot_index = num_memory_snapshots;
    memory_snapshots[num_memory_snapshots].allocated_memory = allocated_memory;
    num_memory_snapshots++;
}

void print_memory_snapshots() {
    for (int i = 0; i < num_memory_snapshots; i++) {
        MemorySnapshot snapshot = memory_snapshots[i];
        printf("Snapshot %zu: %zu bytes allocated\n", snapshot.snapshot_index, snapshot.allocated_memory);
    }
}

int main() {
    take_memory_snapshot();
    int choice;

    do {
        printf("Choose an option:\n");
        printf("1. Take a memory snapshot\n");
        printf("2. Print memory snapshots\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            take_memory_snapshot();
            break;
        case 2:
            print_memory_snapshots();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid option\n");
        }
    } while (1);

    return 0;
}