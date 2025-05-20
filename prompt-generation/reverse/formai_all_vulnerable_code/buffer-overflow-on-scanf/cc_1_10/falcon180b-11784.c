//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_PROCESSES 100
#define BUFFER_SIZE 1024

typedef struct process_info {
    int pid;
    char name[BUFFER_SIZE];
    time_t start_time;
    time_t end_time;
    int exit_status;
    struct rusage usage;
} process_info_t;

process_info_t processes[MAX_PROCESSES];
int num_processes = 0;

void monitor_process(int pid) {
    process_info_t *info = NULL;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            info = &processes[i];
            break;
        }
    }

    if (info == NULL) {
        if (num_processes >= MAX_PROCESSES) {
            printf("Error: maximum number of processes reached\n");
            return;
        }

        info = &processes[num_processes++];
        info->pid = pid;
    }

    if (waitpid(pid, NULL, WNOHANG) == 0) {
        return;
    }

    if (WIFEXITED(info->exit_status)) {
        printf("Process %d (%s) exited with status %d\n", info->pid, info->name, WEXITSTATUS(info->exit_status));
    } else if (WIFSIGNALED(info->exit_status)) {
        printf("Process %d (%s) terminated by signal %d\n", info->pid, info->name, WTERMSIG(info->exit_status));
    } else {
        printf("Process %d (%s) stopped\n", info->pid, info->name);
    }
}

void monitor_ram_usage() {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        printf("Error: failed to get resource usage\n");
        return;
    }

    printf("RAM usage: %ld kB\n", usage.ru_maxrss / 1024);
}

int main() {
    int pid;
    char command[BUFFER_SIZE];

    printf("Enter command to run: ");
    scanf("%s", command);

    if (fork() == 0) {
        execlp(command, command, NULL);
        perror("execlp");
        exit(1);
    }

    while (waitpid(pid, NULL, WNOHANG)!= pid) {
        monitor_ram_usage();
        sleep(1);
    }

    return 0;
}