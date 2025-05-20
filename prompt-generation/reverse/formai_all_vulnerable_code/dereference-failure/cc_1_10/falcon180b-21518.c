//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LEN 16

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LEN];
    unsigned long long ram_usage;
} Process;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    int count = 0;
    Process processes[MAX_PROCESSES];

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        if (strcmp(token, "VmSize:") == 0) {
            token = strtok(NULL, " ");
            processes[count].ram_usage = atoll(token);
            count++;
        }
    }

    fclose(fp);

    fp = fopen("/proc", "r");
    if (fp == NULL) {
        printf("Error opening /proc\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (line[0] >= '0' && line[0] <= '9') {
            token = strtok(line, " ");
            processes[count].pid = atoi(token);
            strcpy(processes[count].name, line);
            count++;
        }
    }

    fclose(fp);

    printf("Process ID\tProcess Name\tRAM Usage (KB)\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%llu\n", processes[i].pid, processes[i].name, processes[i].ram_usage / 1024);
    }

    return 0;
}