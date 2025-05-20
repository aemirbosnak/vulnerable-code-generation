//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int pid;
    char name[16];
    int ram_usage;
} Process;

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    FILE *fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/stat\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int num_matches = sscanf(line, " %d %s %d", &processes[num_processes].pid, processes[num_processes].name, &processes[num_processes].ram_usage);
        if (num_matches!= 3) {
            printf("Error: Could not parse line in /proc/self/stat\n");
            return 1;
        }
        num_processes++;
    }

    fclose(fp);

    while (1) {
        printf("Current RAM usage:\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d: %s (%d KB)\n", processes[i].pid, processes[i].name, processes[i].ram_usage / 1024);
        }

        printf("\nPress enter to update RAM usage...\n");
        getchar();

        fp = fopen("/proc/self/stat", "r");
        if (fp == NULL) {
            printf("Error: Could not open /proc/self/stat\n");
            return 1;
        }

        num_processes = 0;
        while (fgets(line, sizeof(line), fp)!= NULL) {
            int num_matches = sscanf(line, " %d %s %d", &processes[num_processes].pid, processes[num_processes].name, &processes[num_processes].ram_usage);
            if (num_matches!= 3) {
                printf("Error: Could not parse line in /proc/self/stat\n");
                return 1;
            }
            num_processes++;
        }

        fclose(fp);
    }

    return 0;
}