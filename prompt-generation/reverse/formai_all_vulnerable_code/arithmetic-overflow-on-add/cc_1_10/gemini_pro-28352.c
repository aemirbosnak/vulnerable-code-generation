//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <errno.h>

// Custom data structure to store process information
typedef struct process_info {
    pid_t pid;
    char *path;
    long int start_time;
    long int end_time;
    long int cpu_time;
    long int memory_usage;
} process_info_t;

// Function to compare process information based on start time
int compare_processes(const void *a, const void *b) {
    const process_info_t *pa = (const process_info_t *)a;
    const process_info_t *pb = (const process_info_t *)b;

    return pa->start_time - pb->start_time;
}

// Function to print process information
void print_process_info(process_info_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", processes[i].pid);
        printf("Path: %s\n", processes[i].path);
        printf("Start time: %ld\n", processes[i].start_time);
        printf("End time: %ld\n", processes[i].end_time);
        printf("CPU time: %ld\n", processes[i].cpu_time);
        printf("Memory usage: %ld\n\n", processes[i].memory_usage);
    }
}

// Function to launch a process and collect its information
process_info_t launch_process(char *path) {
    process_info_t process;

    struct rusage usage;

    // Fork a new process
    process.pid = fork();

    // Get the current time
    process.start_time = gettimeofday(NULL, NULL);

    if (process.pid == 0) {
        // Child process
        execlp(path, path, NULL);
        exit(0);
    } else if (process.pid > 0) {
        // Parent process
        waitpid(process.pid, NULL, 0);

        // Collect process information
        getrusage(RUSAGE_SELF, &usage);
        process.end_time = gettimeofday(NULL, NULL);
        process.cpu_time = usage.ru_utime.tv_sec * 1000000 + usage.ru_utime.tv_usec;
        process.memory_usage = usage.ru_maxrss;
    } else {
        // Error
        perror("fork");
    }

    return process;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <program1> <program2> ...\n", argv[0]);
        return 1;
    }

    // Launch the processes
    int num_processes = argc - 1;
    process_info_t processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        processes[i] = launch_process(argv[i + 1]);
    }

    // Sort the processes by start time
    qsort(processes, num_processes, sizeof(process_info_t), compare_processes);

    // Print the process information
    print_process_info(processes, num_processes);

    return 0;
}