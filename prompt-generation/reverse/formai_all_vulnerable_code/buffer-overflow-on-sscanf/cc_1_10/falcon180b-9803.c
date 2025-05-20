//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUFFER_SIZE 1024

struct memory_info {
    int pid;
    char name[20];
    int rss;
    int vms;
    float ratio;
};

void get_process_info(int pid, char *name, int *rss, int *vms) {
    FILE *fp;
    char path[20];
    sprintf(path, "/proc/%d/status", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Process not found.\n");
        exit(1);
    }
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (sscanf(line, "Name:\t%s", name) == 1) {
            continue;
        } else if (sscanf(line, "VmRSS:\t%d", rss) == 1) {
            continue;
        } else if (sscanf(line, "VmSize:\t%d", vms) == 1) {
            continue;
        }
    }
    fclose(fp);
}

void print_memory_info(struct memory_info *info) {
    printf("%-5d %-20s %-10d %-10d %.2f%%\n", info->pid, info->name, info->rss, info->vms, info->ratio * 100);
}

int main() {
    int i, num_processes = 0;
    struct memory_info processes[100];
    while (num_processes < 100) {
        int pid = fork();
        if (pid < 0) {
            printf("Error: fork() failed.\n");
            exit(1);
        } else if (pid == 0) {
            exit(0);
        }
        sleep(1);
        char name[20];
        int rss, vms;
        get_process_info(pid, name, &rss, &vms);
        processes[num_processes].pid = pid;
        strcpy(processes[num_processes].name, name);
        processes[num_processes].rss = rss;
        processes[num_processes].vms = vms;
        processes[num_processes].ratio = (float) rss / vms * 100;
        num_processes++;
    }
    printf("+----+-----------------+------+------+--------+\n");
    printf("| PID |       Process     |   RSS |   VMS |  Ratio  |\n");
    printf("+====+=================+======+======+=========\n");
    for (i = 0; i < num_processes; i++) {
        print_memory_info(&processes[i]);
    }
    return 0;
}