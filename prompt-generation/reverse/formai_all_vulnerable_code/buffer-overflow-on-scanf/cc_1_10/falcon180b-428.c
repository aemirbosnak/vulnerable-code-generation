//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME 20
#define MAX_WAIT_TIME 10

typedef struct {
    int id;
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void add_process(Process processes[], int *num_processes) {
    printf("Enter process ID: ");
    scanf("%d", &processes[*num_processes].id);
    printf("Enter process name: ");
    scanf("%s", processes[*num_processes].name);
    printf("Enter burst time: ");
    scanf("%d", &processes[*num_processes].burst_time);
    processes[*num_processes].waiting_time = 0;
    processes[*num_processes].turnaround_time = 0;
    (*num_processes)++;
}

int compare_burst_time(const void *a, const void *b) {
    return (*(Process *)a).burst_time - (*(Process *)b).burst_time;
}

void execute_processes(Process processes[], int num_processes, int quantum) {
    int completed_processes = 0;
    int current_time = 0;
    int current_process_id = 0;

    while (completed_processes < num_processes) {
        if (current_time >= processes[current_process_id].burst_time) {
            processes[current_process_id].turnaround_time = current_time - processes[current_process_id].burst_time + processes[current_process_id].waiting_time;
            completed_processes++;
            current_process_id = (current_process_id + 1) % num_processes;
        } else {
            current_time += quantum;
            processes[current_process_id].waiting_time += quantum;
        }
    }
}

void print_processes(Process processes[], int num_processes) {
    printf("Process ID\tProcess Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\n", processes[i].id, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    srand(time(NULL));

    add_process(processes, &num_processes);
    add_process(processes, &num_processes);
    add_process(processes, &num_processes);

    qsort(processes, num_processes, sizeof(Process), compare_burst_time);

    printf("Processes sorted by burst time:\n");
    print_processes(processes, num_processes);

    execute_processes(processes, num_processes, 2);

    printf("\nProcesses executed with time quantum of 2:\n");
    print_processes(processes, num_processes);

    return 0;
}