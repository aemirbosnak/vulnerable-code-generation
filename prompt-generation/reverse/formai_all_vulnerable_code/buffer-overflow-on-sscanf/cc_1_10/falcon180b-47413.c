//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 16
#define MAX_PROCESS_CMDLINE_LEN 64

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    char cmdline[MAX_PROCESS_CMDLINE_LEN];
    int ram_usage;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void update_ram_usage() {
    FILE *fp;
    char filename[32];
    char line[128];
    int i;

    for (i = 0; i < num_processes; i++) {
        sprintf(filename, "/proc/%d/statm", processes[i].pid);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            continue;
        }
        fgets(line, 128, fp);
        fclose(fp);

        processes[i].ram_usage = atoi(line) * (1024 / 100);
    }
}

void print_processes() {
    int i;

    printf("PID\tName\tRAM Usage (KB)\n");
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    FILE *fp;
    char line[128];
    char name[MAX_PROCESS_NAME_LEN];
    char cmdline[MAX_PROCESS_CMDLINE_LEN];
    int pid;

    fp = fopen("/proc/self/cmdline", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/cmdline.\n");
        return 1;
    }
    fgets(line, 128, fp);
    fclose(fp);

    sscanf(line, "%s %s", name, cmdline);

    printf("Monitoring RAM usage of process '%s'...\n", name);

    update_ram_usage();
    print_processes();

    while (true) {
        sleep(5);
        update_ram_usage();
        print_processes();
    }

    return 0;
}