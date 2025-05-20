//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_PROCESSES 1024

typedef struct {
    char name[16];
    int pid;
    float cpu_usage;
} process_t;

void get_processes(process_t *processes) {
    FILE *fp;
    char path[32] = "/proc/";
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        printf("Error: Failed to open /proc/stat\n");
        exit(1);
    }

    while (fscanf(fp, "cpu %d %*d %*d %*d %*d", &processes[i].cpu_usage)!= EOF) {
        sprintf(path + strlen(path), "%d", processes[i].pid);
        fp = fopen(path, "r");
        if (!fp) {
            printf("Error: Failed to open %s\n", path);
            exit(1);
        }

        fscanf(fp, "comm %s", processes[i].name);
        processes[i].pid = atoi(path);
        fclose(fp);
        i++;
    }

    fclose(fp);
}

void print_processes(process_t *processes, int num_processes) {
    printf("Process\tCPU Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-16s\t%.2f%%\n", processes[i].name, processes[i].cpu_usage);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    get_processes(processes);
    num_processes = sizeof(processes) / sizeof(process_t);

    print_processes(processes, num_processes);

    return 0;
}