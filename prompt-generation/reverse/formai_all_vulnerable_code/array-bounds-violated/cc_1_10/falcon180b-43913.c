//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LEN 100

typedef struct {
    int pid;
    char name[MAX_NAME_LEN];
    int status;
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d %s %d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    DIR *proc_dir;
    struct dirent *proc_ent;
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error opening /proc directory\n");
        return 1;
    }

    while ((proc_ent = readdir(proc_dir))!= NULL) {
        if (proc_ent->d_type == DT_DIR) {
            int pid = atoi(proc_ent->d_name);
            if (pid > 0) {
                char process_name[MAX_NAME_LEN];
                sprintf(process_name, "/proc/%d/cmdline", pid);
                FILE *cmd_file = fopen(process_name, "r");
                if (cmd_file!= NULL) {
                    fgets(processes[num_processes].name, MAX_NAME_LEN, cmd_file);
                    processes[num_processes].pid = pid;
                    fclose(cmd_file);
                    num_processes++;
                }
            }
        }
    }

    closedir(proc_dir);

    while (1) {
        printf("Current processes:\n");
        print_processes(processes, num_processes);
        printf("\nEnter a process ID to terminate: ");
        scanf("%d", &processes[num_processes-1].pid);
        processes[num_processes-1].status = -1;
        num_processes++;
    }

    return 0;
}