//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define PROCESS_NAME_LENGTH 16

typedef struct process {
    int pid;
    char name[PROCESS_NAME_LENGTH];
} Process;

void signal_handler(int signum) {
    exit(0);
}

int main(int argc, char *argv[]) {
    DIR *proc_dir;
    struct dirent *proc_ent;
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    signal(SIGINT, signal_handler);

    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        return 1;
    }

    while ((proc_ent = readdir(proc_dir))!= NULL) {
        if (proc_ent->d_type == DT_DIR && isdigit(proc_ent->d_name[0])) {
            if (num_processes >= MAX_PROCESSES) {
                break;
            }

            int pid = atoi(proc_ent->d_name);
            char path[32];
            snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);

            FILE *cmdline_file = fopen(path, "r");
            if (cmdline_file == NULL) {
                continue;
            }

            char cmdline[PROCESS_NAME_LENGTH];
            if (fgets(cmdline, sizeof(cmdline), cmdline_file) == NULL) {
                fclose(cmdline_file);
                continue;
            }

            size_t len = strlen(cmdline);
            if (len >= PROCESS_NAME_LENGTH) {
                len = PROCESS_NAME_LENGTH - 1;
            }

            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].name, cmdline, len);
            fclose(cmdline_file);

            num_processes++;
        }
    }

    closedir(proc_dir);

    printf("PID\tName\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }

    return 0;
}