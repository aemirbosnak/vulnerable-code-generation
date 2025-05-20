//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 32

struct process {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
};

void get_processes(struct process *processes, int num_processes) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir("/proc");

    if (dir == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            if (count >= num_processes) {
                break;
            }

            processes[count].pid = atoi(entry->d_name);
            strncpy(processes[count].name, entry->d_name, MAX_PROCESS_NAME_LEN);
            processes[count].name[MAX_PROCESS_NAME_LEN - 1] = '\0';

            count++;
        }
    }

    closedir(dir);
}

void display_processes(struct process *processes, int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-32s %d\n", processes[i].name, processes[i].pid);
    }
}

int main(int argc, char *argv[]) {
    int num_processes = 0;
    struct process processes[MAX_PROCESSES];

    if (argc < 2) {
        printf("Usage: %s <number of processes>\n", argv[0]);
        exit(1);
    }

    num_processes = atoi(argv[1]);

    if (num_processes > MAX_PROCESSES) {
        printf("Error: Maximum number of processes is %d.\n", MAX_PROCESSES);
        exit(1);
    }

    get_processes(processes, num_processes);
    display_processes(processes, num_processes);

    return 0;
}