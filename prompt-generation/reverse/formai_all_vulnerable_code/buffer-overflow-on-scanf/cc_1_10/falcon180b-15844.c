//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int pid;
    int status;
    char command[MAX_COMMAND_LENGTH];
    time_t start_time;
    time_t end_time;
} process_t;

void add_process(process_t *processes, int num_processes, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Too many processes.\n");
        return;
    }

    process_t *new_process = &processes[num_processes];

    new_process->pid = fork();

    if (new_process->pid == -1) {
        printf("Error: Fork failed.\n");
        return;
    } else if (new_process->pid == 0) {
        execlp(command, command, NULL);
        exit(1);
    } else {
        new_process->status = 0;
        gettimeofday(&new_process->start_time, NULL);
    }

    num_processes++;
}

void remove_process(process_t *processes, int num_processes, int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            waitpid(pid, &processes[i].status, WNOHANG);
            processes[i] = processes[--num_processes];
            break;
        }
    }
}

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tStatus\tCommand\tStart Time\tEnd Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%s\t%ld\t%ld\n", processes[i].pid, processes[i].status, processes[i].command, processes[i].start_time, processes[i].end_time);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (1) {
        printf("Enter command to schedule (or type 'list' to view processes):\n");
        char command[MAX_COMMAND_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes(processes, num_processes);
        } else {
            add_process(processes, num_processes, command);
        }
    }

    return 0;
}