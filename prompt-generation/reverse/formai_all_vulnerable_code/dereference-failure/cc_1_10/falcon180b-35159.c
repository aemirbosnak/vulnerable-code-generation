//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 256

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

int num_processes = 0;
Process processes[MAX_PROCESSES];

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i+1], sizeof(Process) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[256];

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                snprintf(path, sizeof(path), "/proc/%s/cmdline", ent->d_name);

                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    char command[MAX_COMMAND_LENGTH];
                    if (fgets(command, MAX_COMMAND_LENGTH, file)!= NULL) {
                        add_process(atoi(ent->d_name), command);
                    }

                    fclose(file);
                }
            }
        }

        closedir(dir);
    }

    while (1) {
        print_processes();
        sleep(1);
    }

    return 0;
}