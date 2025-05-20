//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include<stdio.h>
struct process{
    int pid;
    int burst;
    int time_left;
    int priority;
};

//function to find the highest priority process
int findHighestPriority(struct process arr[], int n){
    int highest_priority = -1;
    int process_idx = -1;
    for (int i=0; i<n; i++){
        if (arr[i].time_left > 0 && (highest_priority == -1 || arr[i].priority < highest_priority)){
            highest_priority = arr[i].priority;
            process_idx = i;
        }
    }
    return process_idx;
}

//function to print the Gantt Chart
void printGanttChart(int time, int id){
    printf("%d: P%d\n", time, id+1);
}

//function to implement Priority Scheduling algorithm
void priorityScheduling(struct process arr[], int n){
    int complete_processes = 0;
    int time = 0;
    while (complete_processes != n){
        int idx = findHighestPriority(arr, n);
        if (idx == -1){
            printf("%d: IDLE\n", time);
            time++;
            continue;
        }
        arr[idx].time_left--;
        printGanttChart(time, arr[idx].pid);
        if (arr[idx].time_left == 0){
            complete_processes++;
        }
        time++;
    }
}

int main(){
    int n;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    struct process arr[n];
    printf("Enter the burst time and priority of each process:\n");
    for (int i=0; i<n; i++){
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &arr[i].burst);
        arr[i].time_left = arr[i].burst;
        printf("Priority of P%d: ", i+1);
        scanf("%d", &arr[i].priority);
        arr[i].pid = i;
    }
    printf("Gantt Chart:\n");
    priorityScheduling(arr, n);
    return 0;
}