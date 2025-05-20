//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>

typedef struct {
    pid_t pid;
    char *command;
    char *argv0;
    int status;
} PROCESS;

void print_processes(PROCESS *processes, int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    PROCESS processes[100];
    int num_processes = 0;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (isdigit(ent->d_name[0])) {
                PROCESS process;
                sprintf(process.command, "cat /proc/%s/cmdline", ent->d_name);
                process.pid = atoi(ent->d_name);
                if (system(process.command) == 0) {
                    char *token = strtok(process.command, "\n");
                    process.argv0 = token;
                    processes[num_processes] = process;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}