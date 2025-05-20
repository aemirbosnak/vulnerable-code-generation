//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/reg.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d - %s\n", processes[i].pid, processes[i].command);
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
                int pid = atoi(ent->d_name);

                char command[MAX_COMMAND_LENGTH];
                sprintf(command, "/proc/%d/cmdline", pid);

                int fd = open(command, O_RDONLY);
                if (fd!= -1) {
                    char buffer[MAX_COMMAND_LENGTH];
                    read(fd, buffer, MAX_COMMAND_LENGTH);
                    close(fd);

                    strncpy(processes[num_processes].command, buffer, MAX_COMMAND_LENGTH);
                    processes[num_processes].pid = pid;

                    num_processes++;
                }
            }
        }

        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}