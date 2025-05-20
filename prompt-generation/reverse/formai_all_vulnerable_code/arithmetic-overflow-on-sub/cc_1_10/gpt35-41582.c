//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100

//Declaring the structure for process details
struct process_details{
    int process_no;
    char process_type[MAX];
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

//Function to calculate the waiting time and turnaround time for each process
void calculate_times(struct process_details *details, int n, int quantum)
{
    int time = 0;
    int i, j;

    while(1)
    {
        int flag = 1;
        for(i = 0; i < n; i++)
        {
            if(details[i].remaining_time > 0)
            {
                flag = 0;

                if(details[i].remaining_time > quantum)
                {
                    time += quantum;
                    details[i].remaining_time -= quantum;
                }
                else
                {
                    time += details[i].remaining_time;
                    details[i].waiting_time = time - details[i].burst_time - details[i].arrival_time;
                    details[i].remaining_time = 0;
                }
            }
        }

        if(flag == 1)
            break;
    }

    for(i = 0; i < n; i++)
        details[i].turnaround_time = details[i].waiting_time + details[i].burst_time;
}

//Function to calculate the average waiting time and average turnaround time
void calculate_average_times(struct process_details *details, int n, float *avg_waiting_time, float *avg_turnaround_time)
{
    int i;

    *avg_waiting_time = 0;
    *avg_turnaround_time = 0;

    for(i = 0; i < n; i++)
    {
        *avg_waiting_time += details[i].waiting_time;
        *avg_turnaround_time += details[i].turnaround_time;
    }

    *avg_waiting_time /= n;
    *avg_turnaround_time /= n;
}

//Function to swap two process details structures
void swap(struct process_details *a, struct process_details *b)
{
    struct process_details temp = *a;
    *a = *b;
    *b = temp;
}

//Function to sort the processes based on arrival time
void sort(struct process_details *details, int n)
{
    int i, j;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(details[j].arrival_time > details[j+1].arrival_time)
                swap(&details[j], &details[j+1]);
        }
    }
}

//Function to print the details of processes
void print_details(struct process_details *details, int n)
{
    printf("Process No.\tProcess Type\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");

    for(int i = 0; i < n; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                details[i].process_no, 
                details[i].process_type, 
                details[i].burst_time, 
                details[i].arrival_time, 
                details[i].waiting_time, 
                details[i].turnaround_time);
    }
}

int main()
{
    int n, quantum;
    float avg_waiting_time, avg_turnaround_time;

    printf("Hello Watson, I'm Sherlock, let's solve the CPU Scheduling case.\n");

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process_details details[MAX];

    printf("\n");

    //Accepting the details of each process
    for(int i = 0; i < n; i++)
    {
        printf("Enter the details for process %d:\n", i+1);

        details[i].process_no = i+1;

        printf("Enter the process type (Foreground/Background): ");
        scanf("%s", details[i].process_type);

        printf("Enter the burst time: ");
        scanf("%d", &details[i].burst_time);

        printf("Enter the arrival time: ");
        scanf("%d", &details[i].arrival_time);

        details[i].remaining_time = details[i].burst_time;

        printf("\n");
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    sort(details, n);

    calculate_times(details, n, quantum);

    calculate_average_times(details, n, &avg_waiting_time, &avg_turnaround_time);

    printf("\n");

    printf("The average waiting time is: %.2f\n", avg_waiting_time);
    printf("The average turnaround time is: %.2f\n", avg_turnaround_time);

    printf("\n");

    printf("Let's analyze the details of each process:\n");
    print_details(details, n);
    printf("\n");

    return 0;
}