//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int ram_usage;
} Process;

Process processes[MAX_PROCESSES];
int num_processes = 0;

void read_processes() {
    FILE *fp;
    char line[1024];
    char *token;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    num_processes = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (strcmp(token, "VmSize") == 0) {
            token = strtok(NULL, " ");
            int ram_usage = atoi(token);

            processes[num_processes].pid = getpid();
            strncpy(processes[num_processes].name, "self", 16);
            processes[num_processes].ram_usage = ram_usage;
            num_processes++;
        }
    }

    fclose(fp);
}

void print_processes() {
    printf("PID\tName\tRAM Usage\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].ram_usage);
    }
}

int main() {
    read_processes();
    print_processes();

    return 0;
}