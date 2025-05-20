//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LENGTH 256

typedef struct {
    int pid;
    char name[MAX_NAME_LENGTH];
    char state;
    int ppid;
    int cpu_percent;
    int memory_percent;
} Process;

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%-5d %-15s %c %-5d %-6d%% %-6d%%\n",
               processes[i].pid,
               processes[i].name,
               processes[i].state,
               processes[i].ppid,
               processes[i].cpu_percent,
               processes[i].memory_percent);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                int pid = atoi(ent->d_name);
                if (pid > 0 && pid <= 99999) {
                    char path[50];
                    sprintf(path, "/proc/%d/stat", pid);
                    FILE *file = fopen(path, "r");
                    if (file!= NULL) {
                        fscanf(file, "%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                                &processes[num_processes].pid,
                                processes[num_processes].name,
                                &processes[num_processes].ppid,
                                &processes[num_processes].state,
                                &processes[num_processes].cpu_percent,
                                &processes[num_processes].memory_percent);
                        num_processes++;
                        fclose(file);
                    }
                }
            }
        }
        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}