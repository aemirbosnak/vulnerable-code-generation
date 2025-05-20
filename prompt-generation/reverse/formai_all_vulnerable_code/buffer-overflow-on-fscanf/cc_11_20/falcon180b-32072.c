//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MEGABYTE (1024*1024)

struct process {
    char name[20];
    int pid;
    int ram_usage;
};

int main() {
    FILE *fp;
    struct process proc_list[100];
    int num_procs = 0;
    int i;

    // Open the process list file
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        exit(1);
    }

    // Read in the process list
    while (fscanf(fp, "Name:\t%s\n", proc_list[num_procs].name)!= EOF) {
        proc_list[num_procs].pid = getpid();
        num_procs++;
    }

    // Calculate the RAM usage for each process
    for (i = 0; i < num_procs; i++) {
        char filename[30];
        sprintf(filename, "/proc/%d/status", proc_list[i].pid);
        fp = fopen(filename, "r");
        if (fp == NULL) {
            printf("Error: Could not open /proc/%d/status\n", proc_list[i].pid);
            exit(1);
        }

        char line[100];
        while (fgets(line, sizeof(line), fp)!= NULL) {
            if (strstr(line, "VmSize:")!= NULL) {
                sscanf(line, "VmSize:\t%d kB", &proc_list[i].ram_usage);
                break;
            }
        }

        fclose(fp);
    }

    // Sort the process list by RAM usage
    for (i = 0; i < num_procs - 1; i++) {
        for (int j = i + 1; j < num_procs; j++) {
            if (proc_list[i].ram_usage < proc_list[j].ram_usage) {
                struct process temp = proc_list[i];
                proc_list[i] = proc_list[j];
                proc_list[j] = temp;
            }
        }
    }

    // Print the process list
    printf("Process\tPID\tRAM Usage (MB)\n");
    for (i = 0; i < num_procs; i++) {
        printf("%s\t%d\t%.2f\n", proc_list[i].name, proc_list[i].pid, (double)proc_list[i].ram_usage / MEGABYTE);
    }

    return 0;
}