//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
};

void print_processes(struct process *processes, int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        printf("Error opening log file: %s\n", strerror(errno));
        return 1;
    }

    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (fscanf(log_file, "PID=%d: %s", &processes[num_processes].pid, processes[num_processes].command)!= EOF) {
        num_processes++;
        if (num_processes == MAX_PROCESSES) {
            break;
        }
    }

    fclose(log_file);

    print_processes(processes, num_processes);

    return 0;
}