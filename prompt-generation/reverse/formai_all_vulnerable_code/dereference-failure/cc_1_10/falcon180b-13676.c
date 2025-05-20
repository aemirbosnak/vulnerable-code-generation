//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_ID_LENGTH 20

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
} process_t;

int main() {
    int num_processes = 0;
    process_t *processes = (process_t *)malloc(MAX_PROCESSES * sizeof(process_t));

    FILE *fp;
    char line[256];
    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "VmSize:", 7) == 0) {
            char *value_start = line + 7;
            char *value_end = strchr(value_start, '\n');
            *value_end = '\0';

            int value = atoi(value_start);
            printf("Current RAM usage: %d bytes\n", value);
        } else if (strncmp(line, "Name:", 5) == 0) {
            char *value_start = line + 5;
            char *value_end = strchr(value_start, '\n');
            *value_end = '\0';

            strncpy(processes[num_processes].name, value_start, MAX_PROCESS_NAME_LENGTH);
            processes[num_processes].pid = getpid();
            num_processes++;
        }
    }

    fclose(fp);

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            int pid = processes[i].pid;
            char *name = processes[i].name;

            fp = fopen("/proc/self/status", "r");
            if (fp == NULL) {
                printf("Error opening file\n");
                return 1;
            }

            while (fgets(line, sizeof(line), fp)!= NULL) {
                if (strncmp(line, "VmSize:", 7) == 0) {
                    char *value_start = line + 7;
                    char *value_end = strchr(value_start, '\n');
                    *value_end = '\0';

                    int value = atoi(value_start);
                    printf("RAM usage for process %s (PID %d): %d bytes\n", name, pid, value);
                }
            }

            fclose(fp);
        }

        sleep(5);
    }

    return 0;
}