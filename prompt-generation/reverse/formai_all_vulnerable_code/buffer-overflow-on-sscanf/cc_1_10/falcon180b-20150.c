//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 128

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LEN];
    int cpu_usage;
} Process;

int get_process_info(Process *processes, int num_processes) {
    char proc_path[MAX_PROCESS_NAME_LEN];
    char state;
    int cpu_percent;
    FILE *fp;
    int num_read = 0;

    snprintf(proc_path, MAX_PROCESS_NAME_LEN, "/proc/%d", getpid());
    fp = fopen(proc_path, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while (fgets(proc_path, MAX_PROCESS_NAME_LEN, fp)!= NULL) {
        if (num_read >= num_processes) {
            break;
        }

        if (sscanf(proc_path, "Name: %[^\n]", processes[num_read].name) == 1) {
            num_read++;
        }
    }

    fclose(fp);

    return num_read;
}

void print_processes(Process *processes, int num_processes) {
    printf("PID\tName\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    num_processes = get_process_info(processes, MAX_PROCESSES);

    print_processes(processes, num_processes);

    return 0;
}