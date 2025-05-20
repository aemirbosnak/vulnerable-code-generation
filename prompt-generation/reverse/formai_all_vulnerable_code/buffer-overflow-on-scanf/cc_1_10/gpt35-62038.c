//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_PRIORITY 10

typedef struct {
    int pid;
    int priority;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

Process processes[MAX_SIZE];

void input(Process processes[MAX_SIZE], int size);
void display(Process processes[MAX_SIZE], int size);
void fcfs(Process processes[MAX_SIZE], int size);
void sjf(Process processes[MAX_SIZE], int size);
void priority(Process processes[MAX_SIZE], int size);
void round_robin(Process processes[MAX_SIZE], int size, int time_quantum);
void randomize(Process processes[MAX_SIZE], int size);

int main() {
    int size, time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &size);

    input(processes, size);

    display(processes, size);

    fcfs(processes, size);

    sjf(processes, size);

    priority(processes, size);

    printf("Enter the time quantum for Round Robin algorithm: ");
    scanf("%d", &time_quantum);
    round_robin(processes, size, time_quantum);

    return 0;
}

void input(Process processes[MAX_SIZE], int size) {
    int i;
    srand(time(0));
    for (i = 0; i < size; i++) {
        processes[i].pid = i + 1;
        processes[i].priority = rand() % (MAX_PRIORITY + 1);
        processes[i].burst_time = rand() % (11) + 1;
        processes[i].arrival_time = rand() % (11) + 1;
    }
}

void display(Process processes[MAX_SIZE], int size) {
    int i;
    printf("\nPID\tPriority\tBurst Time\tArrival Time\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, processes[i].burst_time, processes[i].arrival_time);
    }
    printf("\n");
}

void fcfs(Process processes[MAX_SIZE], int size) {
    int i;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    processes[0].completion_time = processes[0].burst_time + processes[0].arrival_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = 0;

    for (i = 1; i < size; i++) {
        processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    for (i = 0; i < size; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }

    avg_turnaround_time /= size;
    avg_waiting_time /= size;

    printf("First Come First Serve Algorithm\n");
    printf("Average Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n\n", avg_turnaround_time, avg_waiting_time);
}

void sjf(Process processes[MAX_SIZE], int size) {
    int i, j;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    Process temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    processes[0].completion_time = processes[0].burst_time + processes[0].arrival_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = 0;

    for (i = 1; i < size; i++) {
        processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    for (i = 0; i < size; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }

    avg_turnaround_time /= size;
    avg_waiting_time /= size;

    printf("Shortest Job First Algorithm\n");
    printf("Average Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n\n", avg_turnaround_time, avg_waiting_time);
}

void priority(Process processes[MAX_SIZE], int size) {
    int i, j;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    Process temp;

    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (processes[i].priority < processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    processes[0].completion_time = processes[0].burst_time + processes[0].arrival_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = 0;

    for (i = 1; i < size; i++) {
        processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    for (i = 0; i < size; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }

    avg_turnaround_time /= size;
    avg_waiting_time /= size;

    printf("Priority Algorithm\n");
    printf("Average Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n\n", avg_turnaround_time, avg_waiting_time);
}

void round_robin(Process processes[MAX_SIZE], int size, int time_quantum) {
    int i, total_burst_time = 0, time = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    int queue[MAX_SIZE], front = 0, rear = -1, length = 0;

    for (i = 0; i < size; i++) {
        total_burst_time += processes[i].burst_time;
    }

    while (time < total_burst_time) {
        for (i = 0; i < size; i++) {
            if (processes[i].burst_time > 0 && processes[i].arrival_time <= time) {
                rear++;
                queue[rear] = i;
                length++;
            }
        }

        if (length == 0) {
            time++;
            continue;
        }

        int current = queue[front];
        if (processes[current].burst_time > time_quantum) {
            processes[current].burst_time -= time_quantum;
            time += time_quantum;
        } else {
            time += processes[current].burst_time;
            processes[current].burst_time = 0;
            processes[current].completion_time = time;
            processes[current].turnaround_time = processes[current].completion_time - processes[current].arrival_time;
            processes[current].waiting_time = processes[current].turnaround_time - processes[current].burst_time;
            front++;
            length--;
        }

        rear++;
        queue[rear] = current;
    }

    for (i = 0; i < size; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }

    avg_turnaround_time /= size;
    avg_waiting_time /= size;

    printf("Round Robin Algorithm with time quantum of %d\n", time_quantum);
    printf("Average Turnaround Time: %.2f\nAverage Waiting Time: %.2f\n\n", avg_turnaround_time, avg_waiting_time);
}

void randomize(Process processes[MAX_SIZE], int size) {
    int i;
    srand(time(0));
    for (i = 0; i < size; i++) {
        processes[i].priority = rand() % (MAX_PRIORITY + 1);
        processes[i].burst_time = rand() % (11) + 1;
        processes[i].arrival_time = rand() % (11) + 1;
    }
}