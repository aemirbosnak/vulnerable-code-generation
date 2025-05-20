//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1000

typedef struct {
    char name[16];
    int pid;
    int rss;
} process;

process processes[MAX_PROCESSES];
int num_processes = 0;

void update_process_list() {
    FILE* fp;
    char line[1024];
    char* token;
    int i;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "Name:") == 0) {
            strcpy(processes[num_processes].name, strtok(NULL, ":"));
        } else if (strcmp(token, "Pid:") == 0) {
            processes[num_processes].pid = atoi(strtok(NULL, ":"));
        } else if (strcmp(token, "VmSize:") == 0) {
            processes[num_processes].rss = atoi(strtok(NULL, ":")) * 1024; // Convert to bytes
        }

        num_processes++;
    }

    fclose(fp);
}

void print_process_list() {
    int i;

    for (i = 0; i < num_processes; i++) {
        printf("%-16s %6d %8d KB\n", processes[i].name, processes[i].pid, processes[i].rss / 1024);
    }
}

int main() {
    int interval, i;

    printf("Enter update interval (in seconds): ");
    scanf("%d", &interval);

    while (1) {
        update_process_list();
        print_process_list();

        for (i = 0; i < num_processes; i++) {
            if (processes[i].rss > 1000000) {
                printf("WARNING: Process %s (PID %d) is using more than 1 MB of RAM!\n", processes[i].name, processes[i].pid);
            }
        }

        sleep(interval);
    }

    return 0;
}