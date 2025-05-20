//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
// Task Scheduler in Ada Lovelace Style

#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Task
typedef struct task_struct {
    int task_id; // Unique id to identify each task
    int priority; // Priority of the task
    int arrival_time; // Time at which the task arrives
    int execution_time; // Time to execute the task
    int start_time; // Time at which task starts execution
    int completion_time; // Time at which task completes execution
    int turnaround_time; // Time taken to complete the task
    int waiting_time; // Time spent waiting in the queue
} Task;

// Declare the global variables
Task *task_list;
int num_tasks, quantum;

// Implement the Round Robin Algorithm
void round_robin() {
    int time = 0;
    int *remaining_time = (int*) malloc(sizeof(int)*num_tasks);
    int *in_queue = (int*) malloc(sizeof(int)*num_tasks);
    for (int i=0; i<num_tasks; i++) {
        remaining_time[i] = task_list[i].execution_time;
        in_queue[i] = 1;
    }

    while(1) {
        int all_done = 1;
        for (int i=0; i<num_tasks; i++) {
            if (in_queue[i] == 1) {
                all_done = 0;
                if (remaining_time[i] > 0) {
                    if (remaining_time[i] > quantum) {
                        time += quantum;
                        remaining_time[i] -= quantum;
                    }
                    else {
                        time += remaining_time[i];
                        remaining_time[i] = 0;
                        task_list[i].completion_time = time;
                        task_list[i].turnaround_time = task_list[i].completion_time - task_list[i].arrival_time;
                        task_list[i].waiting_time = task_list[i].turnaround_time - task_list[i].execution_time;
                        in_queue[i] = 0;
                    }
                }
            }
        }
        if (all_done == 1) {
            break;
        }
    }
    free(remaining_time);
    free(in_queue);
}

// Implement the Bubble Sort Algorithm to sort the tasks by arrival time
void bubble_sort() {
    for (int i=0; i<num_tasks; i++) {
        for (int j=0; j<num_tasks-i-1; j++) {
            if (task_list[j].arrival_time > task_list[j+1].arrival_time) {
                Task temp = task_list[j];
                task_list[j] = task_list[j+1];
                task_list[j+1] = temp;
            }
        }
    }
}

int main() {
    // Get input from the user
    printf("Enter the number of tasks to be scheduled: ");
    scanf("%d", &num_tasks);

    task_list = (Task*) malloc(sizeof(Task)*num_tasks);

    printf("Enter the quantum time for the scheduler: ");
    scanf("%d", &quantum);

    printf("Enter the details of each task in the order of task_id, priority, arrival_time, execution_time:\n");
    for (int i=0; i<num_tasks; i++) {
        scanf("%d %d %d %d", &task_list[i].task_id, &task_list[i].priority, &task_list[i].arrival_time, &task_list[i].execution_time);
    }

    bubble_sort();

    round_robin();

    // Display the details of each task
    printf("Task\tPriority\tArrival Time\tExecution Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i=0; i<num_tasks; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", task_list[i].task_id, task_list[i].priority, task_list[i].arrival_time, task_list[i].execution_time, task_list[i].completion_time, task_list[i].turnaround_time, task_list[i].waiting_time);
    }

    free(task_list);
    return 0;
}