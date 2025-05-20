//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BURST_TIME 100
#define MAX_PROCESS 10
#define MAX_TIME_SLICE 10

void sjf_scheduling(int *arrival_time, int *burst_time, int n);
void round_robin_scheduling(int *arrival_time, int *burst_time, int n);
void lottery_scheduling(int *arrival_time, int *burst_time, int n);

int main() {
    int arrival_time[MAX_PROCESS];
    int burst_time[MAX_PROCESS];
    int n, choice;

    printf("Welcome to the surreal CPU scheduling program!\n");
    printf("Enter the number of processes (limit: %d): ", MAX_PROCESS);
    scanf("%d", &n);

    printf("Enter arrival times and burst times for each process:\n");
    for(int i=0; i<n; i++) {
        printf("Process %d - Arrival time: ", i+1);
        scanf("%d", &arrival_time[i]);
        printf("Process %d - Burst time: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("Choose your surreal scheduling algorithm:\n");
    printf("1 - SJF (Shortest Job First)\n");
    printf("2 - Round Robin\n");
    printf("3 - Lottery\n");
    printf("Choice: ");
    scanf("%d", &choice);

    // Simulating random arrival times (just for the surrealism)
    srand(time(NULL));
    for(int i=0; i<n; i++) {
        arrival_time[i] += rand() % (n+1);
    }

    printf("\n===== Original List =====\n");
    printf("P# | AT  | BT\n");
    printf("===|=====|===\n");
    for(int i=0; i<n; i++) {
        printf("P%d | %2d  | %2d\n", i+1, arrival_time[i], burst_time[i]);
    }

    switch(choice) {
        case 1:
            sjf_scheduling(arrival_time, burst_time, n);
            break;
        case 2:
            round_robin_scheduling(arrival_time, burst_time, n);
            break;
        case 3:
            lottery_scheduling(arrival_time, burst_time, n);
            break;
        default:
            printf("Invalid choice. Please try again.");
            break;
    }

    return 0;
}

// Shortest Job First (SJF) scheduling algorithm implementation
void sjf_scheduling(int *arrival_time, int *burst_time, int n) {
    int new_burst_time[MAX_PROCESS];
    int waiting_time[MAX_PROCESS];
    int completion_time[MAX_PROCESS];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Sorting the processes by burst time (shortest job first)
    for(int i=0; i<n; i++) {
        new_burst_time[i] = burst_time[i];
    }
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(new_burst_time[i] > new_burst_time[j]) {
                int tmp = new_burst_time[i];
                new_burst_time[i] = new_burst_time[j];
                new_burst_time[j] = tmp;

                tmp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = tmp;
            }
        }
    }

    // Calculating the waiting time and completion time for each process
    int current_time = arrival_time[0];
    for(int i=0; i<n; i++) {
        waiting_time[i] = current_time - arrival_time[i];
        if(waiting_time[i] < 0) {
            waiting_time[i] = 0;
            current_time = arrival_time[i];
        }
        current_time += new_burst_time[i];
        completion_time[i] = current_time;
        total_waiting_time += waiting_time[i];
        total_turnaround_time += completion_time[i] - arrival_time[i];
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    printf("\n===== SJF Scheduling Result =====\n");
    printf("P# | AT  | BT  | CT  | WT  | TAT\n");
    printf("===|=====|====|====|====|====\n");
    for(int i=0; i<n; i++) {
        printf("P%d | %2d  | %2d | %2d | %2d | %2d\n", i+1, arrival_time[i], new_burst_time[i], completion_time[i], waiting_time[i], completion_time[i]-arrival_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Round Robin scheduling algorithm implementation
void round_robin_scheduling(int *arrival_time, int *burst_time, int n) {
    int remaining_burst_time[MAX_PROCESS];
    int waiting_time[MAX_PROCESS];
    int completion_time[MAX_PROCESS];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int time_slice, current_time=0, flag=0;

    // Setting the time slice for the surreal round robin
    srand(time(NULL));
    time_slice = rand() % MAX_TIME_SLICE + 1;

    // Initializing the remaining burst time for each process
    for(int i=0; i<n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    // Simulating surreal quantum fluctuations
    for(int i=0; i<MAX_BURST_TIME; i++) {
        if(i % time_slice == 0 && i > 0) {
            flag = (flag+1) % n;
        }
        if(remaining_burst_time[flag] > 0) {
            remaining_burst_time[flag]--;
            current_time++;
        } else {
            flag = (flag+1) % n;
        }
    }

    // Calculating the waiting time and completion time for each process
    for(int i=0; i<n; i++) {
        waiting_time[i] = current_time - burst_time[i] - arrival_time[i];
        completion_time[i] = current_time - arrival_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += completion_time[i] - arrival_time[i];
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    printf("\n===== Round Robin Scheduling Result =====\n");
    printf("P# | AT  | BT  | CT  | WT  | TAT\n");
    printf("===|=====|====|====|====|====\n");
    for(int i=0; i<n; i++) {
        printf("P%d | %2d  | %2d | %2d | %2d | %2d\n", i+1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], completion_time[i]-arrival_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

// Lottery scheduling algorithm implementation
void lottery_scheduling(int *arrival_time, int *burst_time, int n) {
    int waiting_time[MAX_PROCESS];
    int completion_time[MAX_PROCESS];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_tickets = n * n;
    int winning_ticket, chosen_process=0;

    // Assigning tickets for each process (surreal lottery)
    srand(time(NULL));
    int tickets[n];
    for(int i=0; i<n; i++) {
        tickets[i] = rand() % n + 1;
        total_tickets += tickets[i];
    }

    // Simulating surreal lottery drawing
    srand(time(NULL));
    winning_ticket = rand() % total_tickets + 1;
    for(int i=0; i<n; i++) {
        if(winning_ticket <= tickets[i]) {
            chosen_process = i;
            break;
        }
        winning_ticket -= tickets[i];
    }

    // Calculating the waiting time and completion time for each process
    for(int i=0; i<n; i++) {
        waiting_time[i] = 0;
    }
    for(int i=0; i<n; i++) {
        if(i == chosen_process) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = 0;
        }
    }
    total_waiting_time = 0;
    total_turnaround_time = 0;
    for(int i=0; i<n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += completion_time[i] - arrival_time[i];
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    printf("\n===== Lottery Scheduling Result =====\n");
    printf("P# | AT  | BT  | CT  | WT  | TAT\n");
    printf("===|=====|====|====|====|====\n");
    for(int i=0; i<n; i++) {
        printf("P%d | %2d  | %2d | %2d | %2d | %2d\n", i+1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], completion_time[i]-arrival_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}