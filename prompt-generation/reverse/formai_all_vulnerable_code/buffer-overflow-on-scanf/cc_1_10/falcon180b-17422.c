//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_PROCESS_ID_LENGTH 10

struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int id;
    int ram_usage;
};

int main() {
    int num_processes = 0;
    struct process *processes = malloc(MAX_PROCESSES * sizeof(struct process));

    while (1) {
        printf("\nRAM USAGE MONITOR\n");
        printf("==================\n");

        printf("Enter the number of processes you want to monitor (max %d): ", MAX_PROCESSES);
        scanf("%d", &num_processes);

        if (num_processes > MAX_PROCESSES) {
            printf("Error: Number of processes cannot exceed %d.\n", MAX_PROCESSES);
            continue;
        }

        printf("Enter the name and ID of each process:\n");
        for (int i = 0; i < num_processes; i++) {
            printf("Process %d:\n", i + 1);
            printf("Name: ");
            scanf("%s", processes[i].name);
            printf("ID: ");
            scanf("%d", &processes[i].id);
        }

        int total_ram_usage = 0;
        for (int i = 0; i < num_processes; i++) {
            processes[i].ram_usage = rand() % 100;
            total_ram_usage += processes[i].ram_usage;
        }

        printf("\nCurrent RAM usage:\n");
        printf("--------------------\n");
        printf("Total RAM usage: %d%%\n", total_ram_usage);
        for (int i = 0; i < num_processes; i++) {
            printf("Process %d (%s) - RAM usage: %d%%\n", processes[i].id, processes[i].name, processes[i].ram_usage);
        }

        free(processes);
    }

    return 0;
}