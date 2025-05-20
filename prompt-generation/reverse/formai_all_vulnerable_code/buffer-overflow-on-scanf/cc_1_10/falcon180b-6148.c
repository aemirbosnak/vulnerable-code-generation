//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_PROCESSES 100

//structure to hold process information
typedef struct process {
    int pid;
    char name[20];
    int cpu_usage;
} PROCESS;

//function to read process information from /proc/pid/stat
void get_process_info(int pid, PROCESS *process) {
    FILE *file;
    char filename[10];
    sprintf(filename, "/proc/%d/stat", pid);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Process %d not found.\n", pid);
        exit(1);
    }
    fscanf(file, "%*s %*s %*s %*s %*s %*s %d", &(process->cpu_usage));
    fclose(file);
}

//function to print process information
void print_process(PROCESS process) {
    printf("PID: %d\tName: %s\tCPU Usage: %d%%\n", process.pid, process.name, process.cpu_usage);
}

//function to sort processes based on CPU usage
int compare_cpu_usage(const void *a, const void *b) {
    PROCESS *process1 = (PROCESS *)a;
    PROCESS *process2 = (PROCESS *)b;
    if (process1->cpu_usage > process2->cpu_usage)
        return -1;
    else if (process1->cpu_usage < process2->cpu_usage)
        return 1;
    else
        return 0;
}

//main function
int main(int argc, char *argv[]) {
    int i, num_processes = 0;
    PROCESS processes[MAX_PROCESSES];

    //get number of processes to monitor
    printf("Enter number of processes to monitor: ");
    scanf("%d", &num_processes);

    //get process information
    for (i = 0; i < num_processes; i++) {
        printf("Enter PID of process %d: ", i+1);
        scanf("%d", &(processes[i].pid));
        sprintf(processes[i].name, "Process %d", processes[i].pid);
        get_process_info(processes[i].pid, &(processes[i]));
    }

    //sort processes based on CPU usage
    qsort(processes, num_processes, sizeof(PROCESS), compare_cpu_usage);

    //print process information
    printf("\nProcess\tCPU Usage\n");
    for (i = 0; i < num_processes; i++) {
        print_process(processes[i]);
    }

    return 0;
}