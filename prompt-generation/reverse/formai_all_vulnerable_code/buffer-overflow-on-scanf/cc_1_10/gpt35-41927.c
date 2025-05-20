//FormAI DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

struct task{
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
};

int main(){
    int n, i, j, time = 0;
    int total_waiting_time = 0, total_turn_around_time = 0;
    float avg_waiting_time, avg_turn_around_time;
    struct task tasks[10], temp;

    printf("Enter the number of tasks: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("\nEnter the priority, arrival time and burst time of task %d: ", i+1);
        scanf("%d %d %d", &tasks[i].priority, &tasks[i].arrival_time, &tasks[i].burst_time);
        tasks[i].remaining_time = tasks[i].burst_time;
        tasks[i].id = i+1;
    }

    // Implementing Priority Scheduling
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(tasks[i].priority < tasks[j].priority){
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }

    printf("\nGantt chart:\n\n");
    printf("Task\t Arrival Time\t Burst Time\t Completion Time\t Turn Around Time\t Waiting Time\n\n");

    for(i = 0; i < n; i++){
        if(time < tasks[i].arrival_time)
            time = tasks[i].arrival_time;
        tasks[i].completion_time = time + tasks[i].remaining_time;
        tasks[i].turn_around_time = tasks[i].completion_time - tasks[i].arrival_time;
        tasks[i].waiting_time = tasks[i].turn_around_time - tasks[i].burst_time;
        total_waiting_time += tasks[i].waiting_time;
        total_turn_around_time += tasks[i].turn_around_time;
        time = tasks[i].completion_time;
        printf(" %d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", tasks[i].id, tasks[i].arrival_time, tasks[i].burst_time, tasks[i].completion_time, tasks[i].turn_around_time, tasks[i].waiting_time);
    }

    avg_waiting_time = (float)total_waiting_time/n;
    avg_turn_around_time = (float)total_turn_around_time/n;

    printf("\nAverage Waiting Time: %.2f\nAverage Turn Around Time: %.2f\n\n", avg_waiting_time, avg_turn_around_time);

    return 0;
}