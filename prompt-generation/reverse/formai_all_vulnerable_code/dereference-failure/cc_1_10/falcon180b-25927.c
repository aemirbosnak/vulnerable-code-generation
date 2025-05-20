//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MEMORY_BLOCK_SIZE 1024

typedef struct {
    pid_t pid;
    char command[1024];
    unsigned long long memory_usage;
} Process;

void update_processes() {
    FILE *fp;
    char line[1024];
    char *token;
    Process *processes = malloc(MAX_PROCESSES * sizeof(Process));
    int num_processes = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "VmSize:", 8) == 0) {
            token = strtok(line, " ");
            processes[num_processes].memory_usage = strtoull(token, NULL, 10) * MEMORY_BLOCK_SIZE;
            num_processes++;
        }
    }

    fclose(fp);

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            token = strtok(line, " ");
            strcpy(processes[num_processes].command, token);
            num_processes++;
        }
    }

    fclose(fp);

    printf("Process\t\tMemory Usage (KB)\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%llu\n", processes[i].command, processes[i].memory_usage / 1024);
    }

    free(processes);
}

int main() {
    while (1) {
        update_processes();
        sleep(5);
    }

    return 0;
}