//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME 20

struct process {
    int id;
    char name[MAX_PROCESS_NAME];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void display_table(struct process processes[], int num_processes) {
    printf("Process ID\tProcess Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    int choice;

    do {
        printf("\nCPU Scheduling Algorithms Example Program\n");
        printf("1. Add Process\n");
        printf("2. Display Processes\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_processes >= MAX_PROCESSES) {
                    printf("Maximum number of processes reached!\n");
                }
                else {
                    printf("Enter process ID: ");
                    scanf("%d", &processes[num_processes].id);
                    printf("Enter process name: ");
                    scanf("%s", processes[num_processes].name);
                    printf("Enter arrival time: ");
                    scanf("%d", &processes[num_processes].arrival_time);
                    printf("Enter burst time: ");
                    scanf("%d", &processes[num_processes].burst_time);
                    num_processes++;
                }
                break;
            case 2:
                display_table(processes, num_processes);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);

    return 0;
}