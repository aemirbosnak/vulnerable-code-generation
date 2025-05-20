//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_COLUMNS 5
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_PROCESS_ID_LENGTH 20

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    char id[MAX_PROCESS_ID_LENGTH];
    int pid;
    int ppid;
    int status;
} Process;

void print_header() {
    printf("Process ID | Process Name | Parent ID | Status\n");
}

void print_process(Process *p) {
    printf("%-10d | %-20s | %-10d | %c\n", p->pid, p->name, p->ppid, p->status == 0? 'Z' : 'R');
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp;
    char line[128];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "Name:\t%s", processes[num_processes].name);
    num_processes++;

    fgets(line, sizeof(line), fp);
    sscanf(line, "State:\t%c", &processes[num_processes].status);
    num_processes++;

    fgets(line, sizeof(line), fp);
    sscanf(line, "Pid:\t%d", &processes[num_processes].pid);
    num_processes++;

    fgets(line, sizeof(line), fp);
    sscanf(line, "PPid:\t%d", &processes[num_processes].ppid);
    num_processes++;

    fclose(fp);

    print_header();

    for (int i = 0; i < num_processes; i++) {
        print_process(&processes[i]);
    }

    return 0;
}