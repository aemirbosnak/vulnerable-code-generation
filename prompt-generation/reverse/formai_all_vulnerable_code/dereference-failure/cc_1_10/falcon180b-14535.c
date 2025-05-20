//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d, Command: %s, Status: %d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR && isdigit(ent->d_name[0])) {
                Process process;
                sprintf(process.command, "ls /proc/%s/cmdline", ent->d_name);
                process.pid = atoi(ent->d_name);
                process.status = 0;
                if (num_processes < MAX_PROCESSES) {
                    processes[num_processes] = process;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    for (int i = 0; i < num_processes; i++) {
        pid_t child_pid = fork();
        if (child_pid == 0) {
            system(processes[i].command);
            exit(0);
        } else if (child_pid < 0) {
            perror("fork");
        } else {
            int status;
            waitpid(child_pid, &status, 0);
            processes[i].status = status;
        }
    }

    print_processes(processes, num_processes);

    return 0;
}