//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_TASKS 10
#define TIME_QUANTUM 2

typedef struct {
    char name[20];
    int burst_time;
    int remaining_time;
} Task;

void print_tasks(Task tasks[], int count) {
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < count; i++) {
        printf("Task Name: %s | Burst Time: %d | Remaining Time: %d\n", 
                tasks[i].name, tasks[i].burst_time, tasks[i].remaining_time);
    }
    printf("\n");
}

void round_robin(Task tasks[], int count) {
    int time = 0; // Keeps track of time

    while (1) {
        int all_done = 1; // Flag to check if all tasks are done
        for (int i = 0; i < count; i++) {
            if (tasks[i].remaining_time > 0) {
                all_done = 0; // There are still tasks remaining
                if (tasks[i].remaining_time > TIME_QUANTUM) {
                    // The task can run for the full time quantum
                    printf("Time %d: Executing %s for %d units.\n", 
                            time, tasks[i].name, TIME_QUANTUM);
                    sleep(TIME_QUANTUM); // Simulate task execution time
                    tasks[i].remaining_time -= TIME_QUANTUM;
                    time += TIME_QUANTUM;
                } else {
                    // The task can run for its remaining time
                    printf("Time %d: Executing %s for %d units.\n", 
                            time, tasks[i].name, tasks[i].remaining_time);
                    sleep(tasks[i].remaining_time); // Simulate task execution time
                    time += tasks[i].remaining_time;
                    tasks[i].remaining_time = 0; // Mark task as finished
                    printf("Time %d: %s completed.\n", time, tasks[i].name);
                }
            }
        }
        if (all_done) {
            printf("All tasks are completed. Exiting...\n");
            break;
        }
        print_tasks(tasks, count); // Print tasks after each round
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int task_count;

    printf("Welcome to the Curious Task Scheduler!\n");
    printf("How many tasks would you like to schedule (up to %d)? ", MAX_TASKS);
    scanf("%d", &task_count);

    if (task_count > MAX_TASKS || task_count <= 0) {
        fprintf(stderr, "Error: Please enter a valid number of tasks.\n");
        return 1;
    }

    for (int i = 0; i < task_count; i++) {
        printf("Enter name for Task %d: ", i + 1);
        scanf("%s", tasks[i].name);
        printf("Enter burst time for Task %s: ", tasks[i].name);
        scanf("%d", &tasks[i].burst_time);
        tasks[i].remaining_time = tasks[i].burst_time; // Initialize remaining time
    }

    // Start the round-robin scheduling
    printf("\nStarting the Round Robin Task Scheduler...\n");
    round_robin(tasks, task_count);

    return 0;
}