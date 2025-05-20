//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fcfs(int num, int *burst_time){

    int waiting_time[num], turnaround_time[num], total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;

    //Calculating Waiting time for first Process
    waiting_time[0] = 0;
    for(int i=1; i<num; i++){
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        total_waiting_time += waiting_time[i];
    }

    //Calculating Turnaround time for each Process
    for(int i=0; i<num; i++){
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    //Calculating Averages
    average_waiting_time = (float)total_waiting_time / (float)num;
    average_turnaround_time = (float)total_turnaround_time / (float)num;

    //Printing Results
    printf("\nFCFS Scheduling Algorithm:\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\n");
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

void sjf(int num, int *burst_time){

    int waiting_time[num], turnaround_time[num], remaining_time[num], shortest_job, total_waiting_time = 0, total_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;

    //Copying Burst Time into Remaining Time array
    for(int i=0; i<num; i++){
        remaining_time[i] = burst_time[i];
    }

    //Finding Shortest Job for each iteration
    for(int i=0; i<num; i++){
        shortest_job = i;
        for(int j=0; j<num; j++){
            if(remaining_time[j] < remaining_time[shortest_job] && remaining_time[j] >= 0){
                shortest_job = j;
            }
        }
        remaining_time[shortest_job] = -1; //Marking Job as Completed
        waiting_time[shortest_job] = i == 0 ? 0 : turnaround_time[i-1]; //Calculating Waiting Time for Completed Job
        total_waiting_time += waiting_time[shortest_job]; //Adding the Waiting Time to Total Waiting Time
        turnaround_time[shortest_job] = waiting_time[shortest_job] + burst_time[shortest_job]; //Calculating Turnaround Time for Completed Job
        total_turnaround_time += turnaround_time[shortest_job]; //Adding the Turnaround Time to Total Turnaround Time
    }

    //Calculating Averages
    average_waiting_time = (float)total_waiting_time / (float)num;
    average_turnaround_time = (float)total_turnaround_time / (float)num;

    //Printing Results
    printf("\nSJF Scheduling Algorithm:\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\n");
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

void round_robin(int num, int *burst_time){

    int time_quantum = 4, remaining_time[num], waiting_time[num], turnaround_time[num], total_waiting_time = 0, total_turnaround_time = 0, time = 0, flag = 0;
    float average_waiting_time, average_turnaround_time;

    //Copying Burst Time into Remaining Time array
    for(int i=0; i<num; i++){
        remaining_time[i] = burst_time[i];
    }

    //Running Round Robin Algorithm
    while(1){
        flag = 0; //Setting Flag for Checking if all Jobs have Completed
        for(int i=0; i<num; i++){
            if(remaining_time[i] > 0){
                flag = 1; //Setting Flag to 1 for indicating Jobs Remaining
                if(remaining_time[i] > time_quantum){
                    time += time_quantum; //Adding Time Quantum to Time
                    remaining_time[i] -= time_quantum; //Reducing Remaining Time by Time Quantum
                }
                else{
                    time += remaining_time[i]; //Adding Remaining Time to Time
                    waiting_time[i] = time - burst_time[i]; //Calculating waiting time for Completed Job
                    total_waiting_time += waiting_time[i]; //Adding the Waiting Time to Total Waiting Time
                    remaining_time[i] = 0; //Marking Job as Completed
                    turnaround_time[i] = time; //Calculating Turnaround Time for Completed Job
                    total_turnaround_time += turnaround_time[i]; //Adding the Turnaround Time to Total Turnaround Time
                }
            }
        }
        if(flag == 0){
            break; //Breaking Loop if all Jobs have Completed
        }
    }

    //Calculating Averages
    average_waiting_time = (float)total_waiting_time / (float)num;
    average_turnaround_time = (float)total_turnaround_time / (float)num;

    //Printing Results
    printf("\nRound Robin Scheduling Algorithm:\n\n");
    printf("Process\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("\n");
    printf("Average Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

int main(){

    int num, burst_time[20];
    printf("Enter the Number of Processes (Maximum 20): ");
    scanf("%d", &num);
    printf("\nEnter the Burst Time of Processes:\n");
    for(int i=0; i<num; i++){
        printf("P[%d]: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    //Generating Random Seed for Shuffle Function
    srand(time(NULL));

    //Shuffling the Process Order (To represent the Arrival of Jobs)
    for(int i=num-1; i>0; i--){
        int j = rand() % (i+1);
        int temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
    }

    fcfs(num, burst_time);
    sjf(num, burst_time);
    round_robin(num, burst_time);

    return 0;
}