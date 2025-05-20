//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process {
    char name[20];
    int burst_time;
    int arrival_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void greet_king() {
    printf("Hear ye! Hear ye! Welcome to the Kingdom of CPU Scheduling.\n");
    printf("In this realm, we will craft the fair policies for our brave knights (processes).\n");
}

void display_processes(Process *processes, int n) {
    printf("\nThe list of noble knights and their quests:\n");
    printf("%-15s %-15s %-15s %-15s\n", "Knight", "Burst Time", "Arrival Time", "Remaining Time");
    for (int i = 0; i < n; i++) {
        printf("%-15s %-15d %-15d %-15d\n", processes[i].name, processes[i].burst_time, processes[i].arrival_time, processes[i].remaining_time);
    }
}

void sjf_schedule(Process *processes, int n) {
    int time = 0, completed = 0, min_burst_time_index = -1;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    while (completed != n) {
        min_burst_time_index = -1;
        int min_burst_time = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].remaining_time > 0 &&
                processes[i].remaining_time < min_burst_time) {
                min_burst_time = processes[i].remaining_time;
                min_burst_time_index = i;
            }
        }

        if (min_burst_time_index != -1) {
            processes[min_burst_time_index].remaining_time--;
            if (processes[min_burst_time_index].remaining_time == 0) {
                completed++;
                time++;
                processes[min_burst_time_index].turnaround_time = time - processes[min_burst_time_index].arrival_time;
                processes[min_burst_time_index].waiting_time = processes[min_burst_time_index].turnaround_time - processes[min_burst_time_index].burst_time;
                avg_waiting_time += processes[min_burst_time_index].waiting_time;
                avg_turnaround_time += processes[min_burst_time_index].turnaround_time;
            } else {
                time++;
            }
        } else {
            time++;
        }
    }

    printf("\nThe saga of waiting and turnaround times:\n");
    printf("%-15s %-15s %-15s\n", "Knight", "Waiting Time", "Turnaround Time");
    for (int i = 0; i < n; i++) {
        printf("%-15s %-15d %-15d\n", processes[i].name, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nThe average waiting time shall be: %.2f\n", avg_waiting_time / n);
    printf("The average turnaround time shall be: %.2f\n", avg_turnaround_time / n);
}

int main() {
    greet_king();

    int n;
    printf("How many brave knights (processes) shall we dispatch? ");
    scanf("%d", &n);
    Process *processes = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        printf("Enter the name of knight %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter the burst time for %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the arrival time for %s: ", processes[i].name);
        scanf("%d", &processes[i].arrival_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    display_processes(processes, n);
    sjf_schedule(processes, n);

    free(processes);
    return 0;
}