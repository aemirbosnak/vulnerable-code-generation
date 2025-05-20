//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 16

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int mem_usage;
} process_t;

int main() {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;
    process_t processes[MAX_PROCESSES];

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/status\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize") == 0) {
            processes[i].mem_usage = atoi(strtok(NULL, " "));
            strncpy(processes[i].name, "Main Process", MAX_PROCESS_NAME_LENGTH);
            processes[i].pid = getpid();
            i++;
        }
    }

    fclose(fp);

    while (1) {
        system("clear");
        printf("RAM Usage Monitor\n");
        printf("--------------------\n");

        for (int j = 0; j < i; j++) {
            printf("%d. %s (%d)\n", j + 1, processes[j].name, processes[j].mem_usage);
        }

        printf("\nPress any key to refresh...\n");
        getchar();
    }

    return 0;
}