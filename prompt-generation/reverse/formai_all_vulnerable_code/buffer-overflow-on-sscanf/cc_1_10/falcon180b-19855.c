//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_PROCESSES 10

struct process {
    int pid;
    char name[16];
    float cpu_usage;
};

void get_process_info(struct process *processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (i >= NUM_PROCESSES) {
            break;
        }

        token = strtok(line, " ");
        sscanf(token, "%d", &processes[i].pid);

        token = strtok(NULL, " ");
        sscanf(token, "%s", processes[i].name);

        processes[i].cpu_usage = 0.0;
        i++;
    }

    fclose(fp);
}

void print_process_info(struct process *processes) {
    int i;

    for (i = 0; i < NUM_PROCESSES; i++) {
        if (processes[i].pid > 0) {
            printf("%-5d %-16s %-10.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
        }
    }
}

int main() {
    struct process processes[NUM_PROCESSES];

    get_process_info(processes);
    sleep(1);
    get_process_info(processes);

    print_process_info(processes);

    return 0;
}