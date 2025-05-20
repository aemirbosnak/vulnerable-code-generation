//FormAI DATASET v1.0 Category: Task Scheduler ; Style: detailed
// C Program for Task Scheduler 
#include <stdio.h> 
#include <stdlib.h> 

struct Task { 
    int task_id; 
    char task_name[20]; 
    int arrival_time; 
    int burst_time; 
    int priority; 
    int waiting_time; 
    int turnaround_time; 
    int completion_time; 
}; 

int compare_arrival_time(const void* a, const void* b) { 
    return (((const struct Task*)a)->arrival_time - ((const struct Task*)b)->arrival_time); 
} 

int compare_priority(const void* a, const void* b) { 
    return (((const struct Task*)b)->priority - ((const struct Task*)a)->priority); 
} 

int main() { 
    // Taking input from user for the number of tasks to be scheduled
    int n; 
    printf("Enter the number of tasks to be scheduled: "); 
    scanf("%d", &n); 

    // Creating an array of tasks, each with different attributes
    struct Task tasks[n]; 

    // Taking input of attributes of each task from user
    for (int i = 0; i < n; ++i) { 
        printf("Enter the attributes for Task %d:\n", i+1); 
        tasks[i].task_id = i+1; 
        printf("Task Name: "); 
        scanf("%s", tasks[i].task_name); 
        printf("Arrival Time: "); 
        scanf("%d", &tasks[i].arrival_time); 
        printf("Burst Time: "); 
        scanf("%d", &tasks[i].burst_time); 
        printf("Priority (1-10): "); 
        scanf("%d", &tasks[i].priority); 
        printf("\n"); 
    } 

    // Sorting the tasks based on their arrival time
    qsort(tasks, n, sizeof(struct Task), compare_arrival_time); 

    int current_time = 0; 
    int last_completion_time = 0; 

    // Calculating waiting time, turnaround time, completion time for each task
    for (int i = 0; i < n; ++i) { 
        if (tasks[i].arrival_time > current_time) { 
            current_time = tasks[i].arrival_time; 
        } 

        tasks[i].waiting_time = current_time - tasks[i].arrival_time; 

        current_time += tasks[i].burst_time; 
        tasks[i].completion_time = current_time; 

        tasks[i].turnaround_time = tasks[i].completion_time - tasks[i].arrival_time; 

        last_completion_time = tasks[i].completion_time; 
    } 

    // Calculating average waiting time and average turnaround time
    float avg_waiting_time = 0.0; 
    float avg_turnaround_time = 0.0; 

    for (int i = 0; i < n; ++i) { 
        avg_waiting_time += tasks[i].waiting_time; 
        avg_turnaround_time += tasks[i].turnaround_time; 
    } 

    avg_waiting_time /= n; 
    avg_turnaround_time /= n; 

    printf("Id\tName\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n"); 

    // Printing the details of each task
    for (int i = 0; i < n; ++i) { 
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", tasks[i].task_id, tasks[i].task_name, tasks[i].arrival_time, tasks[i].burst_time, tasks[i].priority, tasks[i].waiting_time, tasks[i].turnaround_time, tasks[i].completion_time); 
    } 

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time); 
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time); 

    // Sorting the tasks based on their priority
    qsort(tasks, n, sizeof(struct Task), compare_priority); 

    printf("\nTask order based on priority: "); 

    // Printing the order in which tasks are executed based on their priority
    for (int i = 0; i < n; ++i) { 
        printf("%s ", tasks[i].task_name); 
    } 

    return 0; 
}