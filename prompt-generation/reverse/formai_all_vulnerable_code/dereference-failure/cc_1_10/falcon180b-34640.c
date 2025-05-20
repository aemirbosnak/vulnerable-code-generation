//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 100

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
    int ram_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    FILE *fp;
    char line[1024];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize") == 0) {
            num_processes++;
            if (num_processes >= MAX_PROCESSES) {
                printf("Maximum number of processes reached.\n");
                break;
            }
            processes[num_processes - 1].pid = getpid();
            strcpy(processes[num_processes - 1].name, "Main Process");
            processes[num_processes - 1].ram_usage = atoi(token + strlen(token) + 1) / 1024;
        }
    }

    fclose(fp);

    while (1) {
        system("clear");
        printf("RAM Usage Monitor\n");
        printf("--------------------\n");
        printf("Process Name\tPID\tRAM Usage (KB)\n");
        printf("--------------------\n");

        for (int i = 0; i < num_processes; i++) {
            printf("%s\t%d\t%d\n", processes[i].name, processes[i].pid, processes[i].ram_usage);
        }

        sleep(5);
    }

    return 0;
}