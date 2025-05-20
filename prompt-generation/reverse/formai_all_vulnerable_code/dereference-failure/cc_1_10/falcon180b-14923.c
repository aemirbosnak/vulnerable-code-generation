//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_PROCESSES 1024
#define MAX_COMMAND_LEN 256

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LEN];
    int status;
} Process;

int get_processes(Process *processes, int max_processes) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (isdigit(ent->d_name[0]) && count < max_processes) {
            int pid = atoi(ent->d_name);
            char path[MAX_LINE];
            sprintf(path, "/proc/%d/cmdline", pid);

            FILE *file = fopen(path, "r");
            if (file!= NULL) {
                char command[MAX_COMMAND_LEN];
                fgets(command, MAX_LINE, file);
                fclose(file);

                strcpy(processes[count].command, command);
                processes[count].pid = pid;
                processes[count].status = -1;

                count++;
            }
        }
    }

    closedir(dir);
    return count;
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;
    int status;
    int i = 0;

    num_processes = get_processes(processes, MAX_PROCESSES);

    while (1) {
        printf("\n");
        for (i = 0; i < num_processes; i++) {
            printf("%d ", processes[i].pid);
            printf("%-20s", processes[i].command);
            printf("%d\n", processes[i].status);
        }

        fflush(stdout);
        usleep(100000);
    }

    return 0;
}