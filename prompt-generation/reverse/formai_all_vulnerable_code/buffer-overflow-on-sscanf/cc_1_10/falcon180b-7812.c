//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100

typedef struct process {
    int pid;
    char name[20];
    int status;
} Process;

void print_processes(Process* processes, int num_processes) {
    printf("PID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int get_process_info(Process* processes, int num_processes) {
    FILE* fp;
    char line[80];
    int i = 0;

    fp = popen("ps -ax", "r");
    if (fp == NULL) {
        printf("Error opening ps\n");
        return -1;
    }

    while (fgets(line, 80, fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }
        sscanf(line, "%d\t%s\t%d", &processes[i].pid, processes[i].name, &processes[i].status);
        i++;
    }

    pclose(fp);
    return 0;
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        get_process_info(processes, MAX_PROCESSES);
        num_processes = MAX_PROCESSES;
        print_processes(processes, num_processes);
        sleep(5);
    }

    return 0;
}