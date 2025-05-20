//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 32

typedef struct process_info {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    unsigned long long ram_usage;
} process_info_t;

void get_process_info(process_info_t processes[], int num_processes) {
    FILE *fp;
    char path[64];
    char line[1024];
    char *token;
    int i = 0;

    snprintf(path, sizeof(path), "/proc/%d/statm", getpid());
    fp = fopen(path, "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fgets(line, sizeof(line), fp);
    fclose(fp);

    token = strtok(line, " ");
    processes[i].pid = atoi(token);

    token = strtok(NULL, " ");
    processes[i].ram_usage = atoll(token);

    strncpy(processes[i].name, "RAM usage monitor", MAX_PROCESS_NAME_LEN);
    i++;

    num_processes = i;
}

void print_process_info(process_info_t processes[], int num_processes) {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%d: %s (%llu bytes)\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main(int argc, char *argv[]) {
    process_info_t processes[MAX_PROCESSES];
    int num_processes = 0;

    get_process_info(processes, &num_processes);
    print_process_info(processes, num_processes);

    return 0;
}