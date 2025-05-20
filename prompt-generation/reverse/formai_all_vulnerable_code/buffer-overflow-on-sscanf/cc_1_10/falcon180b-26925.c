//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_PROCS 10

struct proc_info {
    int pid;
    char name[16];
    float cpu_usage;
};

void get_proc_info(struct proc_info *procs, int num_procs) {
    FILE *fp;
    char buf[1024];
    char *line;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(buf, sizeof(buf), fp)!= NULL) {
        if (i >= num_procs) {
            break;
        }

        line = strtok(buf, " ");
        sscanf(line, "%d", &procs[i].pid);

        line = strtok(NULL, " ");
        strncpy(procs[i].name, line, sizeof(procs[i].name)-1);

        procs[i].cpu_usage = 0.0;
        for (int j = 0; j < 4; j++) {
            line = strtok(NULL, " ");
            procs[i].cpu_usage += atof(line);
        }

        i++;
    }

    fclose(fp);
}

void print_proc_info(struct proc_info *procs, int num_procs) {
    for (int i = 0; i < num_procs; i++) {
        printf("%-5d %-16s %6.2f%%\n", procs[i].pid, procs[i].name, procs[i].cpu_usage);
    }
}

int main() {
    struct proc_info procs[NUM_PROCS];

    get_proc_info(procs, NUM_PROCS);
    print_proc_info(procs, NUM_PROCS);

    return 0;
}