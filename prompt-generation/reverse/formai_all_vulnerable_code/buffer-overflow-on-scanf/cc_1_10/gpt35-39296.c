//FormAI DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include<stdio.h> 
#include<stdlib.h> 

// Task structure 
struct task { 
    int id; // ID of the task 
    int priority; // Priority of the task 
    int arrival_time; // Arrival time of the task 
    int burst_time; // Burst time (execution time) of the task 
    int remaining_time; // Remaining time of the task 
}; 

// Function to swap two tasks 
void swap_task(struct task* a, struct task* b) { 
    struct task temp = *a; 
    *a = *b; 
    *b = temp; 
} 

// Function to sort tasks based on arrival time 
void sort_by_arrival(struct task* tasks, int n) { 
    int i, j; 
    for (i = 0; i < n-1; i++) { 
        for (j = 0; j < n-i-1; j++) { 
            if (tasks[j].arrival_time > tasks[j+1].arrival_time) { 
                swap_task(&tasks[j], &tasks[j+1]); 
            } 
        } 
    } 
} 

// Function to sort tasks based on priority
void sort_by_priority(struct task* tasks, int n) {
    int i, j;
    for (i = 0; i < n-1; i++) { 
        for (j = 0; j < n-i-1; j++) {
            if (tasks[j].priority < tasks[j+1].priority) {
                swap_task(&tasks[j], &tasks[j+1]);
            }
        }
    }
}

// Function to simulate task execution 
void execute_task(struct task* t) { 
    printf("Executing task %d...\n", t->id); 
    t->remaining_time--; 
} 

int main() {
    int n, i;
    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    struct task tasks[n];
    for (i = 0; i < n; i++) {
        printf("Enter arrival time of task %d: ", i+1);
        scanf("%d", &tasks[i].arrival_time);
        printf("Enter burst time of task %d: ", i+1);
        scanf("%d", &tasks[i].burst_time);
        printf("Enter priority of task %d: ", i+1);
        scanf("%d", &tasks[i].priority);
        tasks[i].remaining_time = tasks[i].burst_time;
        tasks[i].id = i+1;
    }

    sort_by_arrival(tasks, n);

    int time = 0, completed = 0, index = 0;
    while (completed < n) {
        // Sort tasks based on priority for the current time
        int j, num_priority = 0;
        for (j = index; j < n && tasks[j].arrival_time <= time; j++) {
            if (tasks[j].priority >= 10) {
                num_priority++;
            }
        }

        struct task priority_tasks[num_priority];
        int k = 0;
        for (j = index; j < n && tasks[j].arrival_time <= time; j++) {
            if (tasks[j].priority >= 10) {
                priority_tasks[k++] = tasks[j];
            }
        }
        sort_by_priority(priority_tasks, num_priority);

        // Execute highest priority tasks
        for (j = 0; j < num_priority; j++) {
            execute_task(&priority_tasks[j]);
            time++;

            if (priority_tasks[j].remaining_time == 0) {
                printf("Task %d completed.\n", priority_tasks[j].id);
                completed++;
            }
        }

        // Execute remaining tasks in FCFS order
        for (j = index; j < n && tasks[j].arrival_time <= time; j++) {
            if (tasks[j].priority < 10) {
                execute_task(&tasks[j]);
                time++;

                if (tasks[j].remaining_time == 0) {
                    printf("Task %d completed.\n", tasks[j].id);
                    completed++;
                }
            }
        }
        index = j;
    }

    return 0;
}