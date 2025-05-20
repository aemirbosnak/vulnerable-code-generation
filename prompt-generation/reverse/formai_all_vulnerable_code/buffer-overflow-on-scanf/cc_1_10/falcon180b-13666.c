//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void FCFS(Process* processes, int num_processes) {
    int completed_processes = 0;
    int current_time = 0;
    while (completed_processes < num_processes) {
        int min_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].waiting_time <= current_time && (min_index == -1 || processes[i].waiting_time < processes[min_index].waiting_time)) {
                min_index = i;
            }
        }
        if (min_index!= -1) {
            current_time += processes[min_index].burst_time;
            processes[min_index].waiting_time = 0;
            processes[min_index].turnaround_time = current_time - processes[min_index].waiting_time - processes[min_index].burst_time;
            completed_processes++;
        } else {
            current_time++;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    while (num_processes < MAX_PROCESSES) {
        printf("Enter process name (or 'done' to finish): ");
        scanf("%s", processes[num_processes].name);
        if (strcmp(processes[num_processes].name, "done") == 0) {
            break;
        }
        printf("Enter priority (1-10): ");
        scanf("%d", &processes[num_processes].priority);
        printf("Enter burst time: ");
        scanf("%d", &processes[num_processes].burst_time);
        num_processes++;
    }
    FCFS(processes, num_processes);
    printf("Process\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    return 0;
}