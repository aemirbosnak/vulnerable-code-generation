//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 50
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process proc[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
    }
    
    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time = time + remaining_time[i];
                    proc[i].waiting_time = time - proc[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) {
            break;
        }
    }
}

void calculateTurnaroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void displayProcesses(Process proc[], int n) {
    printf("\nYour processes\' results:\n");
    printf("********************************************\n");
    printf("Process Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("********************************************\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", proc[i].name, proc[i].burst_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
    printf("********************************************\n");
}

int main() {
    Process proc[MAX_PROCESSES];
    int n, quantum;

    printf("Welcome to the Silly CPU Scheduler!\n");
    printf("How many processes do you want today? (Max %d) ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n < 1) {
        printf("Oops! That's too many or too few processes! Try between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Give a name to process #%d (max %d characters): ", i + 1, NAME_LENGTH - 1);
        scanf("%s", proc[i].name);
        printf("How much time (in milliseconds) should process %s take to complete? ", proc[i].name);
        scanf("%d", &proc[i].burst_time);
    }

    printf("Okay! Now, what's the magic time quantum? (in milliseconds) ");
    scanf("%d", &quantum);

    printf("Hang in there! Processing...\n");

    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
    displayProcesses(proc, n);

    printf("Silly Scheduler has done its magic! Remember, scheduling takes time, just like your mom takes time to decide on dinner!\n");
    return 0;
}