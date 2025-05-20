//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // maximum number of processes to monitor

// structure to hold process information
typedef struct {
    char name[20]; // process name
    int pid; // process ID
    int ram_usage; // RAM usage in MB
} process_t;

// function to get RAM usage of a process
int get_ram_usage(int pid) {
    FILE *fp;
    char filename[30];
    int ram_usage = 0;

    sprintf(filename, "/proc/%d/statm", pid); // get the process's statm file
    fp = fopen(filename, "r");

    if (fp!= NULL) {
        fscanf(fp, "%*d %*d %*d %*d %*d %d", &ram_usage); // read RAM usage from statm file
        fclose(fp);
    }

    return ram_usage;
}

// function to print process information
void print_process(process_t *process) {
    printf("Process Name: %s\n", process->name);
    printf("Process ID: %d\n", process->pid);
    printf("RAM Usage: %d MB\n\n", process->ram_usage);
}

// main function
int main() {
    int i, j, num_processes;
    process_t *processes;

    // get number of processes to monitor
    printf("Enter the number of processes to monitor (maximum %d): ", MAX_SIZE);
    scanf("%d", &num_processes);

    // allocate memory for process information
    processes = (process_t *) malloc(num_processes * sizeof(process_t));

    // get process information
    printf("Enter the process name and PID for each process:\n");
    for (i = 0; i < num_processes; i++) {
        scanf("%s %d", processes[i].name, &processes[i].pid);
        processes[i].ram_usage = get_ram_usage(processes[i].pid); // get RAM usage
    }

    // print process information
    printf("Process Information:\n");
    for (i = 0; i < num_processes; i++) {
        print_process(&processes[i]);
    }

    // free memory
    free(processes);

    return 0;
}