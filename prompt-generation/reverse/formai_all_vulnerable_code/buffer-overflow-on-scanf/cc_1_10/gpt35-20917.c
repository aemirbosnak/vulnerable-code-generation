//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

// Function to generate random number between min and max.
int generateRand(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// The process structure
struct process{
    int pid; //process id
    int burst_time; //burst time
    int waiting_time; //waiting time
    int turnaround_time; //turnaround time
    int priority; //priority
};

// Function to print the Gantt chart
void printGanttChart(struct process p[], int n){
    printf("\n\n");
    int i;
    for(i=0;i<n;i++){
        printf("| P%d |",p[i].pid);
    }
    printf("\n\n");
}

// Function to print process details
void printProcess(struct process p){
    printf("| P%d | Burst Time: %d | Waiting Time: %d | Turnaround Time: %d | Priority: %d |\n",p.pid,p.burst_time,p.waiting_time,p.turnaround_time,p.priority);
}

// Function to sort processes based on priority
void sortProcesses(struct process p[], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].priority > p[j].priority){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// The Priority Scheduling Function
void priorityScheduling(int no_of_processes, struct process p[]){
    printf("\n\nPriority Scheduling\n\n");
    int i;
    float avg_wt = 0, avg_tat = 0;
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    for(i=1;i<no_of_processes;i++){
        p[i].waiting_time = p[i-1].turnaround_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
    for(i=0;i<no_of_processes;i++){
        avg_wt += p[i].waiting_time;
        avg_tat += p[i].turnaround_time;
        printProcess(p[i]);
    }
    avg_wt /= no_of_processes;
    avg_tat /= no_of_processes;
    printf("\n\nAverage Waiting Time: %.2f\n",avg_wt);
    printf("Average Turnaround Time: %.2f\n",avg_tat);
    printGanttChart(p,no_of_processes);
}

// The Main Function
int main(){
    srand(time(NULL)); // Seed the random number generator
    
    int no_of_processes; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d",&no_of_processes);
    
    struct process p[no_of_processes]; // Array of processes
    
    int i;
    for(i=0;i<no_of_processes;i++){
        p[i].pid = i+1;
        p[i].burst_time = generateRand(1,20); // Burst time between 1 and 20
        p[i].priority = generateRand(1,5); // Priority between 1 and 5
    }
    
    sortProcesses(p,no_of_processes); // Sort the processes by priority
    
    priorityScheduling(no_of_processes,p); // Call the Priority Scheduling function
    
    return 0;
}