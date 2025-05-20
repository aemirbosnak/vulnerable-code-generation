//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d, Command: %s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (pid > 0 && pid <= MAX_PROCESSES) {
                    sprintf(processes[num_processes].command, "ls /proc/%d/cmdline", pid);
                    processes[num_processes].pid = pid;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    for (int i = 0; i < num_processes; i++) {
        FILE *fp;
        char output[MAX_COMMAND_LENGTH];

        fp = popen(processes[i].command, "r");
        if (fp!= NULL) {
            fgets(output, MAX_COMMAND_LENGTH, fp);
            pclose(fp);

            strncpy(processes[i].command, output, MAX_COMMAND_LENGTH - 1);
            processes[i].command[MAX_COMMAND_LENGTH - 1] = '\0';
        } else {
            strcpy(processes[i].command, "N/A");
        }
    }

    print_processes(processes, num_processes);

    return 0;
}