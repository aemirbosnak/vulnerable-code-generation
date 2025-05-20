//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int memory_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    FILE *fp;
    char line[1024];
    char *token;

    // Read the list of processes from the system
    fp = popen("ps -ax -o pid -o comm -o vsz", "r");
    if (fp == NULL) {
        printf("Error: Failed to execute ps command\n");
        exit(1);
    }

    // Parse the list of processes
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, " ");
        int pid = atoi(token);
        token = strtok(NULL, " ");
        strncpy(processes[num_processes].name, token, MAX_PROCESS_NAME_LENGTH);
        processes[num_processes].pid = pid;
        processes[num_processes].memory_usage = atoi(strtok(NULL, " "));
        num_processes++;
    }

    pclose(fp);

    // Monitor the memory usage of the processes
    while (1) {
        for (int i = 0; i < num_processes; i++) {
            fp = fopen("/proc/self/stat", "r");
            if (fp == NULL) {
                printf("Error: Failed to open /proc/self/stat\n");
                exit(1);
            }
            char stat_line[1024];
            fgets(stat_line, sizeof(stat_line), fp);
            fclose(fp);

            char *token = strtok(stat_line, " ");
            int pid = atoi(token);

            if (pid == processes[i].pid) {
                fp = fopen("/proc/self/status", "r");
                if (fp == NULL) {
                    printf("Error: Failed to open /proc/self/status\n");
                    exit(1);
                }
                char status_line[1024];
                fgets(status_line, sizeof(status_line), fp);
                fclose(fp);

                char *vm_start = strtok(status_line, " ");
                char *vm_size = strtok(NULL, " ");
                int memory_usage = atoi(vm_size) - atoi(vm_start);
                processes[i].memory_usage = memory_usage;
            }
        }

        sleep(1);
    }

    return 0;
}