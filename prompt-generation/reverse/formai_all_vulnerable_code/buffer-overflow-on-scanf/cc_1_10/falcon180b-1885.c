//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

// Process structure
typedef struct {
    unsigned int id;
    unsigned int ram_usage;
    char name[32];
} Process;

// Function to compare two processes by their RAM usage
int compare_ram_usage(const void *a, const void *b) {
    const Process *process_a = (const Process *)a;
    const Process *process_b = (const Process *)b;

    if (process_a->ram_usage > process_b->ram_usage) {
        return -1;
    } else if (process_a->ram_usage < process_b->ram_usage) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Initialize process list
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    // Initialize RAM usage array
    unsigned int ram_usage[MAX_PROCESSES];
    memset(ram_usage, 0, sizeof(ram_usage));

    // Prompt user for number of processes
    printf("Enter the number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    // Prompt user for process information
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the ID and name of process %d:\n", i + 1);
        scanf("%d %s", &processes[i].id, processes[i].name);
    }

    // Monitor RAM usage
    while (1) {
        // Print header
        printf("\n");
        printf("ID\tName\tRAM Usage\n");

        // Sort processes by RAM usage
        qsort(processes, num_processes, sizeof(Process), compare_ram_usage);

        // Print process list
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%d KB\n", processes[i].id, processes[i].name, processes[i].ram_usage);
        }

        // Update RAM usage
        for (int i = 0; i < num_processes; i++) {
            ram_usage[i] = rand() % 1000;
        }

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}