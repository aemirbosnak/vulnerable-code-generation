//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 100

struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void add_process(int pid, char* name) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    int i;
    printf("PID\tName\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PROCESS_NAME_LENGTH];
    int i = 0;

    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            snprintf(path, MAX_PROCESS_NAME_LENGTH, "/proc/%s/cmdline", ent->d_name);
            FILE* file = fopen(path, "r");

            if (file!= NULL) {
                char name[MAX_PROCESS_NAME_LENGTH];
                fscanf(file, "%s", name);
                add_process(atoi(ent->d_name), name);
                fclose(file);
            }
        }
    }

    closedir(dir);

    while (1) {
        print_processes();
        sleep(5);
    }

    return 0;
}