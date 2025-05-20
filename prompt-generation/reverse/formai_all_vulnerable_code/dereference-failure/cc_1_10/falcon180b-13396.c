//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("PID\tCommand\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
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
                char path[50];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    fgets(processes[num_processes].command, MAX_COMMAND_LENGTH, file);
                    fclose(file);
                    processes[num_processes].pid = atoi(ent->d_name);
                    processes[num_processes].status = 0;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    while (1) {
        print_processes(processes, num_processes);
        sleep(1);
    }

    return 0;
}