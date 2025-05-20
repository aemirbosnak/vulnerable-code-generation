//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int memory;
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
            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].name, "Program", 16);
            processes[num_processes].memory = atoi(token + strlen("VmSize:"));
            num_processes++;
        }
    }

    fclose(fp);

    while (1) {
        sleep(1);

        fp = fopen("/proc/self/status", "r");
        if (fp == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        memset(processes, 0, sizeof(processes));

        while (fgets(line, sizeof(line), fp)!= NULL) {
            token = strtok(line, ":");
            if (strcmp(token, "VmSize") == 0) {
                int i;
                for (i = 0; i < num_processes; i++) {
                    if (processes[i].pid == getpid()) {
                        processes[i].memory = atoi(token + strlen("VmSize:"));
                        break;
                    }
                }
            }
        }

        fclose(fp);

        printf("Process ID\tProcess Name\tMemory Usage (KB)\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t\t%s\t\t%d\n", processes[i].pid, processes[i].name, processes[i].memory);
        }
    }

    return 0;
}