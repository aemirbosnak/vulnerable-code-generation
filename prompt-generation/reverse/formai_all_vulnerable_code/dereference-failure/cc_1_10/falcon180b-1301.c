//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: could not open /proc directory.\n");
        return 1;
    }

    struct dirent *ent;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && ent->d_name[0] >= '0' && ent->d_name[0] <= '9') {
            int pid = ent->d_name[0] - '0';
            char filename[MAX_COMMAND_LENGTH];
            snprintf(filename, MAX_COMMAND_LENGTH, "/proc/%d/cmdline", pid);

            FILE *file = fopen(filename, "r");
            if (file == NULL) {
                printf("Error: could not open /proc/%d/cmdline.\n", pid);
                continue;
            }

            char command[MAX_COMMAND_LENGTH];
            if (fgets(command, MAX_COMMAND_LENGTH, file) == NULL) {
                printf("Error: could not read /proc/%d/cmdline.\n", pid);
                fclose(file);
                continue;
            }

            processes[num_processes].pid = pid;
            strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH - 1);
            processes[num_processes].command[MAX_COMMAND_LENGTH - 1] = '\0';

            num_processes++;
        }
    }

    closedir(dir);

    print_processes(processes, num_processes);

    return 0;
}