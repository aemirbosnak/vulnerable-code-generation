//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include<stdio.h>

//Defining the structure for each process
struct process{
    int pid; //Process ID
    int burst_time; //Burst time of the process
    int arrival_time; //Arrival time of the process
    int waiting_time; //Waiting time of the process
    int turnaround_time; //Turnaround time of the process
};

//Function for FCFS scheduling algorithm
void fcfs(struct process arr[], int n){
    int completion_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    //Completion time of first process is the arrival time
    completion_time[0] = arr[0].burst_time + arr[0].arrival_time;
    arr[0].turnaround_time = completion_time[0] - arr[0].arrival_time;
    arr[0].waiting_time = 0;
    total_waiting_time += arr[0].waiting_time;
    total_turnaround_time += arr[0].turnaround_time;

    //Calculating completion time, turnaround time and waiting time for each process
    for(int i=1; i<n; i++){
        if(completion_time[i-1] < arr[i].arrival_time){
            completion_time[i] = arr[i].arrival_time + arr[i].burst_time;
        }
        else{
            completion_time[i] = completion_time[i-1] + arr[i].burst_time;
        }
        arr[i].turnaround_time = completion_time[i] - arr[i].arrival_time;
        arr[i].waiting_time = arr[i].turnaround_time - arr[i].burst_time;
        total_waiting_time += arr[i].waiting_time;
        total_turnaround_time += arr[i].turnaround_time;
    }

    //Calculating average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time/(float)n;
    float avg_turnaround_time = (float)total_turnaround_time/(float)n;

    printf("\nFCFS Scheduling Algorithm:\n\n");
    printf("Process ID   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for(int i=0; i<n; i++){
        printf("%d              %d               %d             %d                 %d                    %d\n", arr[i].pid, arr[i].arrival_time, arr[i].burst_time, completion_time[i], arr[i].turnaround_time, arr[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %0.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %0.2f\n\n", avg_turnaround_time);
}

//Function for SJF scheduling algorithm
void sjf(struct process arr[], int n){
    int completion_time[n], total_waiting_time = 0, total_turnaround_time = 0;

    //Copy the burst time array for sorting
    int burst_time_copy[n];
    for(int i=0; i<n; i++){
        burst_time_copy[i] = arr[i].burst_time;
        completion_time[i] = -1;
    }

    //Sorting the burst time array
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(burst_time_copy[i] > burst_time_copy[j]){
                int temp = burst_time_copy[i];
                burst_time_copy[i] = burst_time_copy[j];
                burst_time_copy[j] = temp;
            }
        }
    }

    //Calculating completion time, turnaround time and waiting time for each process
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(burst_time_copy[i] == arr[j].burst_time && completion_time[j] == -1){
                if(i == 0){
                    completion_time[j] = arr[j].burst_time + arr[j].arrival_time;
                    arr[j].turnaround_time = completion_time[j] - arr[j].arrival_time;
                    arr[j].waiting_time = 0;
                    total_waiting_time += arr[j].waiting_time;
                    total_turnaround_time += arr[j].turnaround_time;
                }
                else{
                    completion_time[j] = completion_time[j-1] + arr[j].burst_time;
                    arr[j].turnaround_time = completion_time[j] - arr[j].arrival_time;
                    arr[j].waiting_time = arr[j].turnaround_time - arr[j].burst_time;
                    total_waiting_time += arr[j].waiting_time;
                    total_turnaround_time += arr[j].turnaround_time;
                }
            }
        }
    }

    //Calculating average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time/(float)n;
    float avg_turnaround_time = (float)total_turnaround_time/(float)n;

    printf("\nSJF Scheduling Algorithm:\n\n");
    printf("Process ID   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for(int i=0; i<n; i++){
        printf("%d              %d               %d             %d                 %d                    %d\n", arr[i].pid, arr[i].arrival_time, arr[i].burst_time, completion_time[i], arr[i].turnaround_time, arr[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %0.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %0.2f\n\n", avg_turnaround_time);
}

//Function for Round Robin scheduling algorithm
void round_robin(struct process arr[], int n){
    int time_quantum, total_waiting_time = 0, total_turnaround_time = 0;

    printf("Enter time quantum:\n");
    scanf("%d", &time_quantum);

    int remaining_time[n];
    int completion_time[n];
    for(int i=0; i<n; i++){
        remaining_time[i] = arr[i].burst_time;
        completion_time[i] = -1;
    }

    int time = 0;
    while(1){
        int flag = 0;
        for(int i=0; i<n; i++){
            if(remaining_time[i] > 0){
                flag = 1;
                if(remaining_time[i] > time_quantum){
                    time += time_quantum;
                    remaining_time[i] -= time_quantum;
                }
                else{
                    time += remaining_time[i];
                    completion_time[i] = time;
                    arr[i].turnaround_time = completion_time[i] - arr[i].arrival_time;
                    arr[i].waiting_time = arr[i].turnaround_time - arr[i].burst_time;
                    total_waiting_time += arr[i].waiting_time;
                    total_turnaround_time += arr[i].turnaround_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if(flag == 0){
            break;
        }
    }

    //Calculating average waiting time and turnaround time
    float avg_waiting_time = (float)total_waiting_time/(float)n;
    float avg_turnaround_time = (float)total_turnaround_time/(float)n;

    printf("\nRound Robin Scheduling Algorithm:\n\n");
    printf("Process ID   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    for(int i=0; i<n; i++){
        printf("%d              %d               %d             %d                 %d                    %d\n", arr[i].pid, arr[i].arrival_time, arr[i].burst_time, completion_time[i], arr[i].turnaround_time, arr[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %0.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %0.2f\n\n", avg_turnaround_time);
}

//Main function
int main(){
    int choice, n;
    printf("Enter the number of processes:\n");
    scanf("%d", &n);

    //Creating an array of struct process
    struct process arr[n];

    //Taking input for each process
    for(int i=0; i<n; i++){
        printf("\nEnter details for process %d:\n", i+1);
        arr[i].pid = i+1;
        printf("Enter arrival time:\n");
        scanf("%d", &arr[i].arrival_time);
        printf("Enter burst time:\n");
        scanf("%d", &arr[i].burst_time);
    }

    //Menu for choosing scheduling algorithm
    while(1){
        printf("\nEnter the scheduler you want to use:\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. Shortest Job First (SJF)\n");
        printf("3. Round Robin\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                fcfs(arr, n);
                break;
            case 2:
                sjf(arr, n);
                break;
            case 3:
                round_robin(arr, n);
                break;
            case 4:
                printf("\nExiting...\n\n");
                return 0;
            default:
                printf("\nInvalid choice. Please enter again.\n");
                break;
        }
    }

    return 0;
}