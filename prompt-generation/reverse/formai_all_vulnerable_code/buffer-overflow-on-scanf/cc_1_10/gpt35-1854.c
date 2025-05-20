//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESS 20

// structure representing a process
typedef struct {
    int pid; // process ID
    int arrival_time; // arrival time
    int burst_time; // burst time
} Process;

// function to display the Gantt chart
void display_gantt_chart(char *queue, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("+---");
    }
    printf("+\n");

    for (int i = 0; i < size; i++) {
        printf("| %c ", queue[i]);
    }
    printf("|\n");

    for (int i = 0; i < size; i++) {
        printf("+---");
    }
    printf("+\n");

    printf("0");
    for (int i = 0; i < size; i++) {
        printf("   %d", i + 1);
    }
    printf("\n\n");
}

// function to execute the round robin algorithm
void round_robin(Process processes[], int n, int quantum)
{
    int time = 0; // current time
    int completed = 0; // number of completed processes
    int queue_time[MAX_PROCESS]; // queue time for each process
    int remaining_burst_time[MAX_PROCESS]; // remaining burst time for each process
    char queue[MAX_PROCESS]; // queue to store the order of execution
    int queue_size = 0; // size of the queue

    // initialize queue time and remaining burst time for each process
    for (int i = 0; i < n; i++) {
        queue_time[i] = -1; // -1 indicates the process has not started yet
        remaining_burst_time[i] = processes[i].burst_time;
    }

    // execute processes until all of them are completed
    while (completed < n) {
        // add processes to the queue that have arrived and have not started yet
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && queue_time[i] == -1) {
                queue_time[i] = time;
                queue[queue_size++] = processes[i].pid + 'A';
            }
        }

        // check if a process has been completed
        if (remaining_burst_time[queue[0] - 'A'] == 0) {
            completed++;
            queue_time[queue[0] - 'A'] = -2; // -2 indicates the process has been completed
            queue[0] = '\0'; // remove the process from the queue
            queue_size--;
            if (queue_size > 0) {
                // move the remaining processes in the queue one position to the left
                for (int i = 1; i <= queue_size; i++) {
                    queue[i - 1] = queue[i];
                }
            }
        }

        // execute the next process in the queue for the specified quantum
        if (queue_size > 0) {
            remaining_burst_time[queue[0] - 'A']--;
            time++;
            quantum--;
            if (quantum == 0) {
                // move the first process to the end of the queue
                char first_process = queue[0];
                for (int i = 1; i <= queue_size; i++) {
                    queue[i - 1] = queue[i];
                }
                queue[queue_size - 1] = first_process;
                quantum = 5; // reset quantum
            }
        } else {
            time++;
            quantum = 5; // reset quantum
        }
    }

    display_gantt_chart(queue, queue_size);
}

int main()
{
    int n; // number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i;
    }

    round_robin(processes, n, 5);

    return 0;
}