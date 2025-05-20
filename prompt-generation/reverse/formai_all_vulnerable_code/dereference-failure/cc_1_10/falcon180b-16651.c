//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PROCESS_NAME 20
#define MAX_PROCESS_ID 20

struct process {
    char name[MAX_PROCESS_NAME];
    int pid;
};

void get_processes(struct process *processes, int *num_processes) {
    DIR *dir;
    struct dirent *ent;

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    *num_processes = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
            snprintf(processes[*num_processes].name, MAX_PROCESS_NAME, "%s", ent->d_name);
            processes[*num_processes].pid = atoi(ent->d_name);
            (*num_processes)++;
        }
    }

    closedir(dir);
}

void print_processes(struct process *processes, int num_processes) {
    printf("Process ID\tProcess Name\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    struct process processes[100];
    int num_processes = 0;

    get_processes(processes, &num_processes);
    print_processes(processes, num_processes);

    return 0;
}