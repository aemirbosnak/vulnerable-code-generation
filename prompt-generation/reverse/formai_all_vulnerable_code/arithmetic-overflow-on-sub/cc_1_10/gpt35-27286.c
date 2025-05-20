//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/wait.h>

// function to calculate CPU usage
float calc_cpu_usage(clock_t start_time, clock_t end_time, struct tms start_cpu, struct tms end_cpu) {
    long clktck = sysconf(_SC_CLK_TCK);
    float user_time = (end_cpu.tms_utime - start_cpu.tms_utime) / (float) clktck;
    float sys_time = (end_cpu.tms_stime - start_cpu.tms_stime) / (float) clktck;
    float cpu_time = user_time + sys_time;
    float real_time = (end_time - start_time) / (float) clktck;

    return 100.0 * cpu_time / real_time;
}

int main() {
    clock_t start_time, end_time;
    struct tms start_cpu, end_cpu;

    printf("Starting CPU usage monitor...\n");

    pid_t pid = fork(); // create a child process

    if (pid == 0) {
        // child process: run a CPU-consuming task
        for (int i = 0; i < 100000; i++) {
            for (int j = 0; j < 100000; j++) {
                int k = i * j;
            }
        }
        exit(0); // exit child process
    }
    
    // parent process: monitor child process's CPU usage
    start_time = times(&start_cpu); // get start time and CPU usage
    printf("Child process started with pid %d\n", pid);

    while (1) {
        sleep(1); // wait for 1 second
        end_time = times(&end_cpu); // get end time and CPU usage

        int child_status;
        pid_t res = waitpid(pid, &child_status, WNOHANG);

        if (res == -1) {
            printf("No such process!\n"); // child process not exist
            break;
        } else if (res == 0) {
            float cpu_usage = calc_cpu_usage(start_time, end_time, start_cpu, end_cpu);
            printf("CPU usage: %.2f%%\n", cpu_usage); // print CPU usage
        } else if (res == pid) {
            printf("Child process with pid %d has exited\n", pid);
            break; // child process has exited
        }
    }

    printf("CPU usage monitor finished.\n");
    return 0;
}