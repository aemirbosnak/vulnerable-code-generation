//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

/* Structures to hold information about each process and its boot time */
typedef struct process {
    int id;
    int boot_time;
} process_t;

int main(void) {
    int num_processes;  /* Number of processes input by user */
    int total_boot_time; /* Total boot time of system */

    /* Prompt user for number of processes */
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    /* Dynamically allocate array of process_t structs based on num_processes */
    process_t *processes = (process_t *) malloc(num_processes * sizeof(process_t));

    /* Prompt user for each process's ID and boot time */
    for(int i = 0; i < num_processes; i++) {
        printf("\nEnter ID and boot time for process %d: ", i+1);
        scanf("%d %d", &processes[i].id, &processes[i].boot_time);
    }

    /* Sort processes array based on boot time */
    for(int i = 1; i < num_processes; i++) {
        process_t current_process = processes[i];
        int j = i - 1;
        while(j >= 0 && processes[j].boot_time > current_process.boot_time) {
            processes[j+1] = processes[j];
            j--;
        }
        processes[j+1] = current_process;
    }

    /* Calculate total boot time as sum of all process boot times */
    for(int i = 0; i < num_processes; i++) {
        total_boot_time += processes[i].boot_time;
    }

    /* Print optimized boot order */
    printf("\nOptimized boot order:\n");
    for(int i = 0; i < num_processes; i++) {
        printf("Process %d (ID: %d) - Boot time: %d\n", i+1, processes[i].id, processes[i].boot_time);
    }

    /* Print total boot time */
    printf("\nTotal boot time: %d\n", total_boot_time);

    /* Free dynamically allocated memory */
    free(processes);

    return 0;
}