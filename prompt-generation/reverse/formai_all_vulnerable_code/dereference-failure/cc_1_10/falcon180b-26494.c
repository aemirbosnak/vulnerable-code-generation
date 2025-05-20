//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESS_NAME_LENGTH 100
#define MAX_PROCESS_ID_LENGTH 10
#define MAX_PROCESS_STATUS_LENGTH 50

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
    char status[MAX_PROCESS_STATUS_LENGTH];
} Process;

void print_process(Process *p) {
    printf("%-20s %-10s %-30s\n", p->name, p->id, p->status);
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[50] = "/proc";
    char cmd[100];
    pid_t pid;
    int status;
    Process *processes = NULL;
    int num_processes = 0;

    if ((dir = opendir(path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                sprintf(cmd, "cat %s/%d/status", path, ent->d_ino);
                if (system(cmd) == 0) {
                    pid = atoi(ent->d_name);
                    processes = realloc(processes, sizeof(Process) * ++num_processes);
                    strncpy(processes[num_processes - 1].name, ent->d_name, MAX_PROCESS_NAME_LENGTH - 1);
                    strncpy(processes[num_processes - 1].id, ent->d_name, MAX_PROCESS_ID_LENGTH - 1);
                    strncpy(processes[num_processes - 1].status, "Running", MAX_PROCESS_STATUS_LENGTH - 1);
                }
            }
        }
        closedir(dir);
    }

    for (int i = 0; i < num_processes; i++) {
        print_process(&processes[i]);
    }

    return 0;
}