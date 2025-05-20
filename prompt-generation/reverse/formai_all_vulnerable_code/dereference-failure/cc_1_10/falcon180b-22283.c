//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>

#define MAX_DEPTH 100

typedef struct {
    int pid;
    int depth;
    float usage;
} process;

void get_usage(int pid, float* usage) {
    struct rusage rusage;
    if (getrusage(pid, &rusage) == -1) {
        printf("Error getting process usage for pid %d\n", pid);
        exit(1);
    }
    *usage = (float)rusage.ru_utime.tv_sec + (float)rusage.ru_stime.tv_sec +
            (float)rusage.ru_utime.tv_usec / 1000000.0 +
            (float)rusage.ru_stime.tv_usec / 1000000.0;
}

void print_process(process p, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("%d (%f%%)\n", p.pid, p.usage);
}

void monitor_cpu_usage(int max_depth) {
    process* processes = malloc(sizeof(process) * MAX_DEPTH);
    int num_processes = 0;
    process current_process = {0};

    while (num_processes < MAX_DEPTH) {
        int pid = fork();
        if (pid == 0) {
            // Child process
            sleep(1);
            exit(0);
        } else if (pid > 0) {
            // Parent process
            current_process.pid = pid;
            get_usage(pid, &current_process.usage);
            processes[num_processes] = current_process;
            num_processes++;
        } else {
            // Fork failed
            printf("Error forking process\n");
            exit(1);
        }
    }

    for (int i = 0; i < num_processes; i++) {
        print_process(processes[i], max_depth);
    }

    for (int i = 0; i < num_processes; i++) {
        free(processes[i].pid);
    }
    free(processes);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <max_depth>\n", argv[0]);
        return 1;
    }

    int max_depth = atoi(argv[1]);
    if (max_depth < 1 || max_depth > MAX_DEPTH) {
        printf("Invalid max depth\n");
        return 1;
    }

    monitor_cpu_usage(max_depth);

    return 0;
}