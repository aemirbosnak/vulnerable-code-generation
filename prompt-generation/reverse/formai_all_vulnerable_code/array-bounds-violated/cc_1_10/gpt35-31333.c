//FormAI DATASET v1.0 Category: Task Scheduler ; Style: satisfied
#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct { 
    int id; // Task ID 
    int priority; // Priority of the task 
    int burstTime; // Burst time of the task 
    int arrivalTime; // Arrival time of the task 
} Task; 
  
void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b; 
    *b = temp;
} 
  
void sort(Task tasks[], int n) { 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority) {
                swap(&tasks[j], &tasks[j + 1]); 
            } else if (tasks[j].priority == tasks[j + 1].priority) {
                if (tasks[j].burstTime > tasks[j + 1].burstTime) {
                    swap(&tasks[j], &tasks[j + 1]); 
                } else if (tasks[j].burstTime == tasks[j + 1].burstTime) {
                    if (tasks[j].arrivalTime > tasks[j + 1].arrivalTime) {
                        swap(&tasks[j], &tasks[j + 1]); 
                    }
                }
            }
        }
    }
} 
  
void schedule(Task tasks[], int n) { 
    sort(tasks, n); 
  
    int completionTime[n], turnAroundTime[n], waitingTime[n]; 
  
    completionTime[0] = tasks[0].burstTime + tasks[0].arrivalTime; 
    turnAroundTime[0] = completionTime[0] - tasks[0].arrivalTime; 
    waitingTime[0] = turnAroundTime[0] - tasks[0].burstTime; 
  
    for (int i = 1; i < n; i++) { 
        int minPriority = tasks[i].priority; 
        int index = i; 
        for (int j = i; j < n; j++) { 
            if (tasks[j].arrivalTime <= completionTime[i - 1]) { 
                if (tasks[j].priority > minPriority) { 
                    minPriority = tasks[j].priority; 
                    index = j; 
                } else if (tasks[j].priority == minPriority) { 
                    if (tasks[j].burstTime < tasks[index].burstTime) { 
                        index = j; 
                    } else if (tasks[j].burstTime == tasks[index].burstTime) { 
                        if (tasks[j].arrivalTime < tasks[index].arrivalTime) { 
                            index = j; 
                        } 
                    }
                }
            } else { 
                break; 
            } 
        } 
  
        completionTime[index] = completionTime[i - 1] + tasks[index].burstTime; 
  
        turnAroundTime[index] = completionTime[index] - tasks[index].arrivalTime; 
  
        waitingTime[index] = turnAroundTime[index] - tasks[index].burstTime; 
  
        swap(&tasks[i], &tasks[index]); 
    } 
  
    printf("Task ID\tPriority\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\tCompletion Time\n"); 
    for (int i = 0; i < n; i++) { 
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", tasks[i].id, tasks[i].priority, tasks[i].burstTime, tasks[i].arrivalTime, waitingTime[i], turnAroundTime[i], completionTime[i]); 
    } 
  
    float averageWaitingTime = 0, averageTurnAroundTime = 0; 
    for (int i = 0; i < n; i++) { 
        averageWaitingTime += waitingTime[i]; 
        averageTurnAroundTime += turnAroundTime[i]; 
    } 
    printf("\nAverage Waiting Time: %.2f", averageWaitingTime / n); 
    printf("\nAverage Turn-Around Time: %.2f\n", averageTurnAroundTime / n); 
} 
  
int main() { 
    int n; 

    printf("Enter the number of tasks: "); 
    scanf("%d", &n); 

    Task tasks[n]; 
    for (int i = 0; i < n; i++) { 
        tasks[i].id = i + 1; 
        printf("\nTask %d:\n", i + 1); 
        printf("Enter Priority: "); 
        scanf("%d", &tasks[i].priority); 
        printf("Enter Burst Time: "); 
        scanf("%d", &tasks[i].burstTime); 
        printf("Enter Arrival Time: "); 
        scanf("%d", &tasks[i].arrivalTime); 
    } 
  
    schedule(tasks, n); 
  
    return 0; 
}