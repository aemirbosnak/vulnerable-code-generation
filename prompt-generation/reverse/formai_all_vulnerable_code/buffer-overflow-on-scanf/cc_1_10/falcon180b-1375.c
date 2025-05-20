//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_COMMANDS 50

typedef struct {
    int id;
    char command[MAX_COMMANDS];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

int compare_priority(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return (p1->priority - p2->priority);
}

void execute_process(Process *process) {
    printf("Executing process %d with command %s\n", process->id, process->command);
    sleep(process->burst_time);
}

void add_process(Process *processes, int num_processes, int id, char command[], int priority, int burst_time) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Process table is full\n");
        return;
    }
    strcpy(processes[num_processes].command, command);
    processes[num_processes].id = id;
    processes[num_processes].priority = priority;
    processes[num_processes].burst_time = burst_time;
    num_processes++;
}

void sort_processes(Process *processes, int num_processes) {
    qsort(processes, num_processes, sizeof(Process), compare_priority);
}

void print_processes(Process *processes, int num_processes) {
    printf("Process ID\tCommand\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].command, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add process\n");
        printf("2. Execute processes\n");
        printf("3. Print processes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter process ID: ");
            int id;
            scanf("%d", &id);
            printf("Enter command: ");
            char command[MAX_COMMANDS];
            scanf("%s", command);
            printf("Enter priority: ");
            int priority;
            scanf("%d", &priority);
            printf("Enter burst time: ");
            int burst_time;
            scanf("%d", &burst_time);
            add_process(processes, num_processes, id, command, priority, burst_time);
            break;
        case 2:
            sort_processes(processes, num_processes);
            for (int i = 0; i < num_processes; i++) {
                execute_process(&processes[i]);
            }
            break;
        case 3:
            print_processes(processes, num_processes);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}