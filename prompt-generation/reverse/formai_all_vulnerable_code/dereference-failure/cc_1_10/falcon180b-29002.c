//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_COMMAND_LEN 1024

typedef struct {
    pid_t pid;
    char command[MAX_COMMAND_LEN];
} process_t;

void print_processes(process_t processes[], int count) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;

    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        return 1;
    }

    struct dirent *dent;
    while ((dent = readdir(dir))!= NULL) {
        if (dent->d_type == DT_DIR && isdigit(dent->d_name[0])) {
            int pid = atoi(dent->d_name);
            char path[20];
            sprintf(path, "/proc/%d/cmdline", pid);

            FILE *file = fopen(path, "r");
            if (file == NULL) {
                continue;
            }

            char command[MAX_COMMAND_LEN];
            fgets(command, MAX_COMMAND_LEN, file);
            fclose(file);

            strncpy(processes[count].command, command, MAX_COMMAND_LEN - 1);
            processes[count].command[MAX_COMMAND_LEN - 1] = '\0';
            processes[count].pid = pid;

            count++;
        }
    }

    closedir(dir);

    print_processes(processes, count);

    return 0;
}