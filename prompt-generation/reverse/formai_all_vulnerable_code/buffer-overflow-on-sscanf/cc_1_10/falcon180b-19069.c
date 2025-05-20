//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

enum {
    PROCESS_STATE_RUNNING = 1,
    PROCESS_STATE_STOPPED = 2,
    PROCESS_STATE_ZOMBIE = 3,
    PROCESS_STATE_UNKNOWN = 4
};

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int state;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\tState\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].state);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp = popen("ps -ef", "r");
    char line[MAX_COMMAND_LENGTH];

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_processes >= MAX_PROCESSES) {
            break;
        }

        Process process;
        sscanf(line, "%d\t%[^\t]\t%d", &process.pid, process.command, &process.state);
        processes[num_processes++] = process;
    }

    pclose(fp);

    print_processes(processes, num_processes);

    return 0;
}