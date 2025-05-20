//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct process {
    char name[20];
    int pid;
    int memory_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    char input[100];
    FILE *fp;
    int i, j;

    // Read the list of processes from a file
    fp = fopen("processes.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file processes.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s %d %d", input, &processes[num_processes].pid, &processes[num_processes].memory_usage)!= EOF) {
        strcpy(processes[num_processes].name, input);
        num_processes++;
    }

    fclose(fp);

    // Monitor RAM usage
    while (1) {
        system("free -m > ram_usage.txt");
        fp = fopen("ram_usage.txt", "r");
        if (fp == NULL) {
            printf("Error: Unable to open file ram_usage.txt\n");
            return 1;
        }

        fscanf(fp, "%*s %*s %d", &i);
        fscanf(fp, "%*s %*s %d", &j);

        printf("\nRAM Usage:\n");
        printf("Total: %d MB\n", i);
        printf("Used: %d MB\n", j);
        printf("Free: %d MB\n", i - j);

        for (int k = 0; k < num_processes; k++) {
            printf("\nProcess %s:\n", processes[k].name);
            printf("PID: %d\n", processes[k].pid);
            printf("Memory Usage: %d MB\n", processes[k].memory_usage);
        }

        fclose(fp);
        sleep(5);
    }

    return 0;
}