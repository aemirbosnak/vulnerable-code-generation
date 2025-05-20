//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024
#define MAX_PID_LENGTH 6
#define MAX_STATE_LENGTH 10
#define MAX_CPU_TIME_LENGTH 10
#define MAX_MEMORY_LENGTH 10

// Struct to hold process information
typedef struct process_info {
    char command[MAX_COMMAND_LENGTH];
    char state[MAX_STATE_LENGTH];
    int pid[MAX_PID_LENGTH];
    int cpu_time;
    int memory_usage;
} process_info;

void get_process_info(int pid, process_info *info) {
    char path[MAX_COMMAND_LENGTH];
    sprintf(path, "/proc/%d/cmdline", pid);
    int fd = open(path, O_RDONLY);
    if (fd!= -1) {
        char buf[MAX_COMMAND_LENGTH];
        int bytes_read = read(fd, buf, MAX_COMMAND_LENGTH);
        if (bytes_read > 0) {
            buf[bytes_read - 1] = '\0';
            strcpy(info->command, buf);
        }
        close(fd);
    }

    char state_path[MAX_COMMAND_LENGTH];
    sprintf(state_path, "/proc/%d/status", pid);
    fd = open(state_path, O_RDONLY);
    if (fd!= -1) {
        char buf[MAX_STATE_LENGTH];
        int bytes_read = read(fd, buf, MAX_STATE_LENGTH);
        if (bytes_read > 0) {
            buf[bytes_read - 1] = '\0';
            strcpy(info->state, buf);
        }
        close(fd);
    }

    sprintf(info->pid, "%d", pid);
    info->cpu_time = 0;
    info->memory_usage = 0;
}

void print_process_info(process_info *info) {
    printf("%-15s %-30s %-6s %10d %10d\n", info->command, info->state, info->pid, info->cpu_time, info->memory_usage);
}

int main() {
    int num_processes = 0;
    process_info *process_list = malloc(MAX_PROCESSES * sizeof(process_info));

    while (num_processes < MAX_PROCESSES) {
        int pid = fork();
        if (pid == 0) {
            // Child process
            execlp("sleep", "sleep", "1", NULL);
            perror("execlp");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            process_info *info = &process_list[num_processes];
            get_process_info(pid, info);
            num_processes++;
        } else {
            // Error forking process
            perror("fork");
            exit(1);
        }
    }

    printf("Process ID\tCommand\tState\tCPU Time\tMemory Usage\n");
    for (int i = 0; i < num_processes; i++) {
        print_process_info(&process_list[i]);
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(process_list[i].pid, NULL, 0);
    }

    free(process_list);
    return 0;
}