//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    int priority;       // Task priority (higher number = higher priority)
    int arrival_time;  // Task arrival time
    int burst_time;    // Task burst time
    int remaining_time;// Task remaining time
    int start_time;   // Task start time
    int end_time;     // Task end time
    int waiting_time;  // Task waiting time
    int turnaround_time; // Task turnaround time
    int response_time;  // Task response time
} task;

// Task queue
task task_queue[100];
int task_queue_size = 0;

// Task comparison function (for sorting tasks by priority)
int compare_tasks(const void *a, const void *b) {
    const task *task1 = (const task *)a;
    const task *task2 = (const task *)b;
    return task1->priority - task2->priority;
}

// Task scheduler
void task_scheduler() {
    // Sort tasks by priority
    qsort(task_queue, task_queue_size, sizeof(task), compare_tasks);

    int current_time = 0;
    int completed_tasks = 0;

    // While there are incomplete tasks
    while (completed_tasks < task_queue_size) {
        int next_task_index = -1;
        int next_task_priority = -1;

        // Find the next task with the highest priority and earliest arrival time
        for (int i = 0; i < task_queue_size; i++) {
            if (task_queue[i].arrival_time <= current_time && task_queue[i].remaining_time > 0) {
                if (task_queue[i].priority > next_task_priority) {
                    next_task_index = i;
                    next_task_priority = task_queue[i].priority;
                }
            }
        }

        // If there is no next task, wait for one to arrive
        if (next_task_index == -1) {
            sleep(1);
            current_time++;
            continue;
        }

        // Run the next task
        task_queue[next_task_index].start_time = current_time;
        task_queue[next_task_index].remaining_time--;
        current_time++;

        // If the task is completed, update its statistics
        if (task_queue[next_task_index].remaining_time == 0) {
            task_queue[next_task_index].end_time = current_time;
            task_queue[next_task_index].waiting_time = task_queue[next_task_index].start_time - task_queue[next_task_index].arrival_time;
            task_queue[next_task_index].turnaround_time = task_queue[next_task_index].end_time - task_queue[next_task_index].arrival_time;
            task_queue[next_task_index].response_time = task_queue[next_task_index].start_time - task_queue[next_task_index].arrival_time;
            completed_tasks++;
        }
    }
}

// Main function
int main() {
    // Initialize task queue
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i + 1);
        printf("ID: ");
        scanf("%d", &task_queue[i].id);
        printf("Priority: ");
        scanf("%d", &task_queue[i].priority);
        printf("Arrival time: ");
        scanf("%d", &task_queue[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &task_queue[i].burst_time);
        task_queue[i].remaining_time = task_queue[i].burst_time;
    }

    // Print task queue
    printf("\nTask Queue:\n");
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");
    printf("| ID | Priority | Arrival Time | Burst Time | Remaining Time | Start Time | End Time | Waiting Time | Turnaround Time | Response Time |\n");
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("| %2d | %6d | %10d | %7d | %13d | %10d | %10d | %12d | %15d | %13d |\n",
            task_queue[i].id, task_queue[i].priority, task_queue[i].arrival_time, task_queue[i].burst_time, task_queue[i].remaining_time,
            task_queue[i].start_time, task_queue[i].end_time, task_queue[i].waiting_time, task_queue[i].turnaround_time, task_queue[i].response_time);
    }
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");

    // Run task scheduler
    task_scheduler();

    // Print task statistics
    printf("\nTask Statistics:\n");
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");
    printf("| ID | Priority | Arrival Time | Burst Time | Remaining Time | Start Time | End Time | Waiting Time | Turnaround Time | Response Time |\n");
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("| %2d | %6d | %10d | %7d | %13d | %10d | %10d | %12d | %15d | %13d |\n",
            task_queue[i].id, task_queue[i].priority, task_queue[i].arrival_time, task_queue[i].burst_time, task_queue[i].remaining_time,
            task_queue[i].start_time, task_queue[i].end_time, task_queue[i].waiting_time, task_queue[i].turnaround_time, task_queue[i].response_time);
    }
    printf("+----+-------+----------+--------+-------------+----------+----------+------------+--------------+-------------+\n");

    return 0;
}