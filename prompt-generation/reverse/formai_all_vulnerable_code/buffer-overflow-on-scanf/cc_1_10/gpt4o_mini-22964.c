//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_fcfs(Process processes[], int n) {
    int total_waiting_time = 0;
    printf("\nFirst-Come, First-Served Scheduling:\n");

    processes[0].waiting_time = 0; // First process waits 0
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%s\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Hooray! Scheduling completed joyfully!\n");
}

void calculate_sjn(Process processes[], int n) {
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processes[j].burst_time > processes[j+1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    printf("\nShortest Job Next Scheduling:\n");

    processes[0].waiting_time = 0; // First process waits 0
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%s\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Yay! We've completed SJN scheduling with a smile!\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    // Cheerful welcome
    printf("🎉 Welcome to the CPU Scheduling Simulation! 🎉\n");
    printf("Please enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n <= 0) {
        printf("Oops! Please enter a valid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter arrival time for %s: ", processes[i].name);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
    }

    calculate_fcfs(processes, n);
    calculate_sjn(processes, n);

    printf("🎊 Thank you for using the CPU Scheduling Simulation! 🎊\n");
    return 0;
}