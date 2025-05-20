//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include<stdio.h>

//Structure to store process information
struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

//Function to sort the processes by their priority
void sort_processes_by_priority(struct process* p_array, int n){
    int i, j;
    struct process temp;

    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(p_array[j].priority > p_array[j + 1].priority){
                temp = p_array[j];
                p_array[j] = p_array[j + 1];
                p_array[j + 1] = temp;
            }
        }
    }
}

//Function to calculate waiting time and turnaround time for each process
void calculate_waiting_and_turnaround_time(struct process* p_array, int n){
    int i, j;

    //Set waiting time of first process to 0
    p_array[0].waiting_time = 0;

    //Calculate waiting time for each process by adding burst times of previous processes
    for(i = 1; i < n; i++){
        p_array[i].waiting_time = p_array[i - 1].waiting_time + p_array[i - 1].burst_time;
    }

    //Calculate turnaround time for each process by adding burst time and waiting time of each process
    for(j = 0; j < n; j++){
        p_array[j].turnaround_time = p_array[j].waiting_time + p_array[j].burst_time;
    }
}

//Function to display process information
void display_processes(struct process* p_array, int n){
    int i;

    printf("--------------------------------------------------------------------------\n");
    printf("Process ID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p_array[i].pid, p_array[i].burst_time, p_array[i].arrival_time, p_array[i].priority, p_array[i].waiting_time, p_array[i].turnaround_time);
    }
}

int main(){
    int i, n;
    struct process p_array[20];

    //Reading number of processes from the user
    printf("Enter number of processes: ");
    scanf("%d", &n);

    //Reading process information from the user
    for(i = 0; i < n; i++){
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &p_array[i].burst_time);

        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &p_array[i].arrival_time);

        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &p_array[i].priority);

        p_array[i].pid = i + 1;
    }

    //Sorting the processes by their priority
    sort_processes_by_priority(p_array, n);

    //Calculating waiting time and turnaround time of each process
    calculate_waiting_and_turnaround_time(p_array, n);

    //Displaying process information
    display_processes(p_array, n);

    return 0;
}