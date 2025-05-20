//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main() {
    int pid[10], burst_time[10], wait_time[10], turnaround_time[10], total_time = 0, n, t_time = 0;
    float avg_wait_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        pid[i] = fork();

        if(!pid[i]) {
            // child process
            printf("Child process %d with pid %d started\n", i+1, getpid());
            sleep(burst_time[i]);
            printf("Child process %d with pid %d completed after %d seconds\n", i+1, getpid(), burst_time[i]);
            exit(burst_time[i]);
        }
        else if(pid[i] < 0) {
            printf("Error in creating process!\n");
            exit(1);
        }
    }

    printf("Waiting for child processes to complete...\n");

    // parent process
    for(int i = 0; i < n; i++) {
        int child_pid = waitpid(pid[i], &t_time, 0);
        wait_time[i] = t_time - burst_time[i];
        total_time += wait_time[i];
        turnaround_time[i] = t_time;

        printf("Child process %d with pid %d completed and returned %d\n", i+1, child_pid, WEXITSTATUS(t_time));
    }

    avg_wait_time = (float) total_time / n;
    total_time = 0;

    for(int i = 0; i < n; i++) {
        total_time += turnaround_time[i];
    }

    avg_turnaround_time = (float) total_time / n;

    printf("Average waiting time: %f seconds\n", avg_wait_time);
    printf("Average turnaround time: %f seconds\n", avg_turnaround_time);

    return 0;
}