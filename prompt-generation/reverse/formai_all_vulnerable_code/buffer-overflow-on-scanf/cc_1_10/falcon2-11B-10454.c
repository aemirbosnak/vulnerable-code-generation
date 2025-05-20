//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100 // Number of processes

int process_list[N]; // Array to store process list
int processes[N][2]; // Array to store process info
int burst_time[N]; // Array to store burst time of processes
int arrival_time[N]; // Array to store arrival time of processes
int processes_list[N]; // Array to store sorted process list
int total_burst_time = 0; // Total burst time of processes
int total_arrival_time = 0; // Total arrival time of processes

// Function to implement Shortest Job First (SJF) algorithm
void SJF(int n)
{
    int i, j, k, temp; // Declare variables
    for (i = 0; i < n; i++) // Sort the process list based on burst time
    {
        for (j = i + 1; j < n; j++)
        {
            if (processes[i][1] > processes[j][1])
            {
                temp = processes[i][0];
                processes[i][0] = processes[j][0];
                processes[i][1] = processes[j][1];
                processes[j][0] = temp;
                temp = processes_list[i];
                processes_list[i] = processes_list[j];
                processes_list[j] = temp;
            }
        }
    }
}

// Function to initialize process list
void init(int n)
{
    srand(time(NULL)); // Initialize random seed
    for (int i = 0; i < n; i++)
    {
        arrival_time[i] = rand() % 100; // Generate random arrival time
        burst_time[i] = rand() % 100; // Generate random burst time
        processes[i][0] = i + 1; // Store process ID
        processes[i][1] = arrival_time[i]; // Store arrival time
    }
}

// Function to get the arrival time of a process
int get_arrival_time(int p)
{
    return processes[p][1];
}

// Function to get the burst time of a process
int get_burst_time(int p)
{
    return processes[p][1];
}

// Function to get the process list
int get_processes_list(int n)
{
    return processes_list;
}

int main()
{
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    init(n); // Initialize process list
    SJF(n); // Sort the process list based on burst time
    printf("Process ID \t Arrival Time \t Burst Time \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t %d \t %d \n", i + 1, processes[i][1], processes[i][1]);
    }
    return 0;
}