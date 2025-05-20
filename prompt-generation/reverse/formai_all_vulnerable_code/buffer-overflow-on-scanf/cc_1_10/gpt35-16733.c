//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>

#define MAX_JOBS 100
#define QUANTUM 5 // time quantum for round robin algorithm

struct Job {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
};

// function prototypes
void fcfs(struct Job jobs[], int n);
void sjf(struct Job jobs[], int n);
void priority(struct Job jobs[], int n);
void round_robin(struct Job jobs[], int n);

int main() {
    int n;
    struct Job jobs[MAX_JOBS];
    
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    
    printf("\nEnter the arrival time, burst time, and priority for each job:\n");
    for(int i = 0; i < n; i++) {
        jobs[i].id = i + 1; // set job id
        printf("\nJob %d: ", jobs[i].id);
        scanf("%d %d %d", &jobs[i].arrival_time, &jobs[i].burst_time, &jobs[i].priority);
        jobs[i].remaining_time = jobs[i].burst_time; // set remaining time equal to burst time
    }
    
    printf("\n--- First Come First Serve (FCFS) Scheduling ---\n");
    fcfs(jobs, n);
    
    printf("\n--- Shortest Job First (SJF) Scheduling ---\n");
    sjf(jobs, n);
    
    printf("\n--- Priority Scheduling ---\n");
    priority(jobs, n);
    
    printf("\n--- Round Robin (RR) Scheduling ---\n");
    round_robin(jobs, n);
    
    return 0;
}

void fcfs(struct Job jobs[], int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    
    for(int i = 0; i < n; i++) {
        if(jobs[i].arrival_time > current_time) { // if job hasn't arrived yet, wait
            current_time = jobs[i].arrival_time;
        }
        
        int wait_time = current_time - jobs[i].arrival_time; // calculate wait time
        total_wait_time += wait_time;
        
        int turnaround_time = wait_time + jobs[i].burst_time; // calculate turnaround time
        total_turnaround_time += turnaround_time;
        
        current_time += jobs[i].burst_time; // update current time
        printf("Job %d: wait time = %d, turnaround time = %d\n", jobs[i].id, wait_time, turnaround_time);
    }
    
    printf("Average wait time = %.2f, Average turnaround time = %.2f\n", 
           (float)total_wait_time / n, (float)total_turnaround_time / n);
}

void sjf(struct Job jobs[], int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    
    // sort jobs by burst time
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(jobs[j].burst_time > jobs[j+1].burst_time) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(jobs[i].arrival_time > current_time) { // if job hasn't arrived yet, wait
            current_time = jobs[i].arrival_time;
        }
        
        int wait_time = current_time - jobs[i].arrival_time; // calculate wait time
        total_wait_time += wait_time;
        
        int turnaround_time = wait_time + jobs[i].burst_time; // calculate turnaround time
        total_turnaround_time += turnaround_time;
        
        current_time += jobs[i].burst_time; // update current time
        printf("Job %d: wait time = %d, turnaround time = %d\n", jobs[i].id, wait_time, turnaround_time);
    }
    
    printf("Average wait time = %.2f, Average turnaround time = %.2f\n", 
           (float)total_wait_time / n, (float)total_turnaround_time / n);
}

void priority(struct Job jobs[], int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    
    // sort jobs by priority
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - 1 - i; j++) {
            if(jobs[j].priority > jobs[j+1].priority) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(jobs[i].arrival_time > current_time) { // if job hasn't arrived yet, wait
            current_time = jobs[i].arrival_time;
        }
        
        int wait_time = current_time - jobs[i].arrival_time; // calculate wait time
        total_wait_time += wait_time;
        
        int turnaround_time = wait_time + jobs[i].burst_time; // calculate turnaround time
        total_turnaround_time += turnaround_time;
        
        current_time += jobs[i].burst_time; // update current time
        printf("Job %d: wait time = %d, turnaround time = %d\n", jobs[i].id, wait_time, turnaround_time);
    }
    
    printf("Average wait time = %.2f, Average turnaround time = %.2f\n", 
           (float)total_wait_time / n, (float)total_turnaround_time / n);
}

void round_robin(struct Job jobs[], int n) {
    int total_wait_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    int remaining_jobs = n;
    
    while(remaining_jobs > 0) {
        for(int i = 0; i < n; i++) {
            if(jobs[i].arrival_time <= current_time && jobs[i].remaining_time > 0) { // if job has arrived and has unfinished work
                if(jobs[i].remaining_time <= QUANTUM) { // if job can finish within time quantum
                    current_time += jobs[i].remaining_time; // update current time
                    jobs[i].remaining_time = 0; // mark job as finished
                    remaining_jobs--; // decrement remaining jobs
                }
                else { // otherwise, perform one time quantum of work
                    current_time += QUANTUM; // update current time
                    jobs[i].remaining_time -= QUANTUM; // subtract one time quantum from remaining time
                }
                
                if(jobs[i].remaining_time == 0) { // if job has finished
                    int wait_time = current_time - jobs[i].arrival_time - jobs[i].burst_time; // calculate wait time
                    total_wait_time += wait_time;
                    
                    int turnaround_time = wait_time + jobs[i].burst_time; // calculate turnaround time
                    total_turnaround_time += turnaround_time;
                    
                    printf("Job %d: wait time = %d, turnaround time = %d\n", jobs[i].id, wait_time, turnaround_time);
                }
            }
        }
    }
    
    printf("Average wait time = %.2f, Average turnaround time = %.2f\n", 
           (float)total_wait_time / n, (float)total_turnaround_time / n);
}