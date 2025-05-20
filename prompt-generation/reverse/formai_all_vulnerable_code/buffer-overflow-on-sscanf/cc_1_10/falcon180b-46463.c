//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUF_SIZE 1024
#define PROC_NAME_MAX 16

typedef struct {
    char name[PROC_NAME_MAX];
    int pid;
    float cpu_percent;
} proc_info;

void get_cpu_usage(int pid, float *cpu_percent) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        printf("Error: Failed to get CPU usage\n");
        exit(1);
    }
    *cpu_percent = (float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec / 1000000;
}

void print_proc_info(proc_info *info) {
    printf("%-16s %-6d %-8.2f%%\n", info->name, info->pid, info->cpu_percent);
}

int main() {
    FILE *fp;
    char buf[BUF_SIZE];
    char filename[64] = "/proc/self/status";
    proc_info *procs = NULL;
    int num_procs = 0;
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        exit(1);
    }

    while (fgets(buf, BUF_SIZE, fp)!= NULL) {
        if (strncmp(buf, "Name:", 5) == 0) {
            strncpy(procs[num_procs].name, buf + 6, PROC_NAME_MAX - 1);
            procs[num_procs].name[PROC_NAME_MAX - 1] = '\0';
        } else if (strncmp(buf, "Pid:", 4) == 0) {
            sscanf(buf + 5, "%d", &procs[num_procs].pid);
        }
    }

    fclose(fp);

    for (i = 0; i < num_procs; i++) {
        get_cpu_usage(procs[i].pid, &procs[i].cpu_percent);
    }

    printf("Process\t\tPID\tCPU%\n");
    printf("--------\t\t---\t------\n");

    for (i = 0; i < num_procs; i++) {
        print_proc_info(&procs[i]);
    }

    free(procs);
    return 0;
}