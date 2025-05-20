//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    pid_t pid;
    char process_name[MAX_PROCESS_NAME_LENGTH];
    int process_status;
} Process;

void display_processes(Process *processes, int num_processes) {
    printf("PID\tProcess Name\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].process_name, processes[i].process_status);
    }
}

int get_process_info(pid_t pid, char *process_name, int *process_status) {
    char path[50];
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        return -1;
    }
    fgets(process_name, MAX_PROCESS_NAME_LENGTH, fp);
    fclose(fp);
    *process_status = 0;
    return 0;
}

int main() {
    Process processes[100];
    int num_processes = 0;

    DIR *dp;
    struct dirent *dirp;
    dp = opendir("/proc");
    if (dp == NULL) {
        printf("Error: cannot open /proc directory.\n");
        exit(1);
    }

    while ((dirp = readdir(dp))!= NULL) {
        if (dirp->d_type == DT_DIR) {
            pid_t pid = atoi(dirp->d_name);
            char process_name[MAX_PROCESS_NAME_LENGTH];
            int process_status = 0;

            if (get_process_info(pid, process_name, &process_status) == 0) {
                processes[num_processes].pid = pid;
                strncpy(processes[num_processes].process_name, process_name, MAX_PROCESS_NAME_LENGTH);
                processes[num_processes].process_status = process_status;
                num_processes++;
            }
        }
    }

    closedir(dp);

    display_processes(processes, num_processes);

    return 0;
}